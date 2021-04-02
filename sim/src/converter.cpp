#include "../inc/converter.h"
#pragma warning(push, 0)

using namespace llvm;

Converter::Converter(std::vector<ISA::Instruction>& instBuff) :
	insts(instBuff),
	fmap()
{
	// Create context
	context = std::make_unique<LLVMContext>();
	module  = std::make_unique<Module>("converter", *context);
	builder = std::make_unique<IRBuilder<>>(*context);
	std::vector<Type*> argType(1, Type::getInt8PtrTy(*context));
	fType = FunctionType::get(Type::getVoidTy(*context), argType, false);

	// Create regFile
	llvm::ArrayType* regFileTy = ArrayType::get(builder->getInt32Ty(), REGISTER_NUM);
	module->getOrInsertGlobal("RegFile", regFileTy);
	regFile = module->getNamedGlobal("RegFile");
	regFile->setLinkage(GlobalValue::PrivateLinkage);
	regFile->setAlignment(MaybeAlign(8));
	regFile->setInitializer(ConstantAggregateZero::get(regFileTy));

	createFunctions();
}

void Converter::translate()
{
	for (auto f = fmap.begin(); f != fmap.end(); ++f)
	{
		for (auto bb = f->second.bbinfo.begin(); bb != f->second.bbinfo.end(); ++bb)
		{
			bb->block = BasicBlock::Create(*context, "BB", f->second.function);
		}
		for (auto bb = f->second.bbinfo.begin(); bb != f->second.bbinfo.end(); ++bb)
		{
			builder->SetInsertPoint(bb->block);
			for (uint32_t pc = bb->startPc; pc <= bb->endPc; pc += 4)
			{
			    emitInst(insts[getInstructionIdx(pc)], &(f->second));
			}
			if (bb->isPseudoJump)
			{
				createBranch(bb->endPc + 4, &(f->second));
			}
		}
	}

	// Add return to _start func
	auto start = fmap.find(0x103cc);
	BasicBlock* oneBB = start->second.bbinfo.front().block;
	builder->SetInsertPoint(oneBB);
	builder->CreateRetVoid();

	for (auto f = fmap.begin(); f != fmap.end(); ++f)
	{
		verifyFunction(*(f->second.function), &errs());
	}
	std::error_code er;
	module->print(raw_fd_ostream(StringRef("D:/Users/vkorovin/riscv32-sim/ir.ll"), er), nullptr);
}

void Converter::emitInst(ISA::Instruction inst, FINfo* currentF)
{
	Value* pBuff = currentF->function->getArg(0);
	Value* addr = nullptr;
	Value* dst = nullptr;
	Value* cond = nullptr;
	SmallVector<Value*, 3> srcs;
	switch (inst.getType())
	{
	case ISA::TYPE::R:
		srcs[0] = getRegValue(inst.getRs1());
		srcs[1] = getRegValue(inst.getRs2());
		break;
	case ISA::TYPE::I:
	case ISA::TYPE::SR:
		srcs[0] = getRegValue(inst.getRs1());
		srcs[1] = getConstant(inst.getImm());
		break;
	case ISA::TYPE::S:
	case ISA::TYPE::B:
		srcs[0] = getRegValue(inst.getRs1());
		srcs[1] = getRegValue(inst.getRs2());
		srcs[2] = getConstant(inst.getImm());
		break;
	case ISA::TYPE::U:
	case ISA::TYPE::J:
		srcs[0] = getConstant(inst.getImm());
		break;
	case ISA::TYPE::N:
		break;
	default:
        throw std::string("Unknown instruction type!");
	}

	switch (inst.getOp())
	{
	case::ISA::OP::LUI:
		dst = builder->CreateShl(srcs[0], 12);
		break;
	case ISA::OP::JAL:
	{
		if (inst.getRd() == 1)
		{
			uint32_t fAddr = inst.getPc() + inst.getImm();
			auto proc = fmap.find(fAddr);
			if (proc == fmap.end())
			{
				throw std::string("Function is not in map! Addr: " + std::to_string(fAddr));
			}
			builder->CreateCall(proc->second.function, { pBuff });

			dst = builder->CreateAdd(getConstant(inst.getPc()), getConstant(4));
			storeRegValue(dst, inst.getRd());
		}
		else if (inst.getRd() == 0)
		{
			createBranch(inst.getImm() + inst.getPc(), currentF);
		}
		else
		{
			throw std::string("Jal not supported: " + inst.getName());
		}
		break;
	}
	case ISA::OP::JALR:
	{
		if (inst.getImm() == 0)
		{
			dst = getConstant(inst.getImm() + inst.getPc());
			storeRegValue(dst, inst.getRd());
			builder->CreateRetVoid();
		}
		else
		{
			throw std::string("Jalr not supported: " + inst.getName());
		}
		return;
	}
	case ISA::OP::BEQ:
		cond = builder->CreateICmpEQ(srcs[0], srcs[1]);
		break;
	case ISA::OP::BNE:
		cond = builder->CreateICmpNE(srcs[0], srcs[1]);
		break;
	case ISA::OP::BGE:
		cond = builder->CreateICmpSGE(srcs[0], srcs[1]);
		break;
	case ISA::OP::BLT:
		cond = builder->CreateICmpSLT(srcs[0], srcs[1]);
		break;
	case ISA::OP::LW:
	{
		Value* offset = builder->CreateAdd(srcs[0], srcs[1]);
		addr = builder->CreateBitCast(pBuff, Type::getInt32PtrTy(*context));
		addr = builder->CreateGEP(addr, offset);
		dst = builder->CreateLoad(addr);
		break;
	}
	case ISA::OP::SW:
		addr = builder->CreateBitCast(pBuff, Type::getInt32PtrTy(*context));
		dst = srcs[1];
		break;
	case ISA::OP::ADDI:
	case ISA::OP::ADD:
		dst = builder->CreateAdd(srcs[0], srcs[1]);
		break;
	case ISA::OP::SLTIU:
		dst = builder->CreateICmpULT(srcs[0], srcs[1]);
		dst = builder->CreateZExt(dst, Type::getInt32Ty(*context));
		break;
	case ISA::OP::ANDI:
	case ISA::OP::AND:
		dst = builder->CreateAnd(srcs[0], srcs[1]);
		break;
	case ISA::OP::SLLI:
		dst = builder->CreateShl(srcs[0], inst.getImm());
		break;
	case ISA::OP::SUB:
		dst = builder->CreateSub(srcs[0], srcs[1]);
		break;
	case ISA::OP::EBREAK:
	{
		Function* trap = Intrinsic::getDeclaration(module.get(), Intrinsic::debugtrap);
		builder->CreateCall(trap, std::initializer_list<Value*>{});
		builder->CreateRetVoid();
		break;
	}
	case ISA::OP::ECALL:
		builder->CreateRetVoid();
		break;
	default:
		throw std::string("Unknown instruction!\n" + inst.getName());
	}

	switch (inst.getType())
	{
	case ISA::TYPE::B:
	{
		createBranch(inst.getImm() + inst.getPc(), 
					 currentF,
					 inst.getPc() + 4,
					 cond);
		break;
	}
	case ISA::TYPE::U:
	case ISA::TYPE::R:
	case ISA::TYPE::I:
	case ISA::TYPE::SR:
		storeRegValue(dst, inst.getRd());
		break;
	case ISA::TYPE::S:
	{
		Value* offset = builder->CreateAdd(srcs[0], srcs[2]);
		addr = builder->CreateGEP(addr, offset);
		builder->CreateStore(dst, addr);
		break;
	}
	case ISA::TYPE::J:
		break;
	case ISA::TYPE::N:
		break;
	default:
		throw std::string("Unknown instruction type!");
	}
}


void Converter::createFunctions()
{
	bool nextFunc = true;
	uint32_t key = insts.front().getPc();

	for (auto inst : insts)
	{
		if (nextFunc)
		{
			FINfo funcInfo;
			funcInfo.function = createFunction("Func");
			fmap.insert(std::make_pair(key, funcInfo));
			nextFunc = false;
		}

		if (inst.getOp() == ISA::OP::JAL && inst.getRd() == 1)
		{
			if (fmap.find(inst.getPc() + inst.getImm()) == fmap.end())
			{
				key = inst.getPc() + inst.getImm();
				nextFunc = true;
			}
		}
	}

	std::vector<uint32_t> fAddresses;
	for (auto f : fmap)
	{
		fAddresses.push_back(f.first);
	}

	// Split functions into basic blocks
	for (auto f = fmap.begin(); f != fmap.end(); ++f)
	{
		// Find function borders
		uint32_t start = f->first;
		uint32_t end = f->first + 4;
		for (uint32_t i = 0; i < fAddresses.size(); ++i)
		{
			if (start < fAddresses[i])
			{
				end = fAddresses[i];
				break;
			}
		}

		createJumpTable(&(f->second), f->first, end);
	}
}

void Converter::createJumpTable(FINfo* func, uint32_t startPc, uint32_t endPc)
{
	int instIdx = getInstructionIdx(startPc);
	if (instIdx == -1)
	{
		throw std::string("Instruction not found! pc: " + std::to_string(startPc));
	}

	int funcSize = (endPc - startPc) / 4;
	std::list<BBInfo> blocks;
	bool isNewBB = true;

	for (int i = instIdx; i < (instIdx + funcSize); ++i)
	{
		if (isNewBB)
		{
			BBInfo bb;
			bb.startPc = insts[i].getPc();
			bb.endPc = endPc - 4; // special for start_
			blocks.push_back(bb);

			isNewBB = false;
		}

		ISA::OP opCode = insts[i].getOp();
		if (opCode == ISA::OP::JALR || opCode == ISA::OP::ECALL || opCode == ISA::OP::EBREAK)
		{
			blocks.back().endPc = insts[i].getPc();
			break;
		}

		if (insts[i].getType() == ISA::TYPE::B || (opCode == ISA::OP::JAL && insts[i].getRd() == 0))
		{
			blocks.back().endPc = insts[i].getPc();
			isNewBB = true;
		}
	}

	for (auto it : blocks)
	{
		if (it.isPseudoJump)
		{
			continue;
		}

		int lastInstIdx = getInstructionIdx(it.endPc);
		if (lastInstIdx == -1)
		{
			throw std::string("Instruction not found! pc: " + std::to_string(it.endPc));
		}

		ISA::OP opCode = insts[lastInstIdx].getOp();
		if (insts[lastInstIdx].getType() == ISA::TYPE::B ||
			(insts[lastInstIdx].getType() == ISA::TYPE::J && insts[lastInstIdx].getRd() == 0))
		{
			uint32_t jump = insts[lastInstIdx].getPc() + insts[lastInstIdx].getImm();

			bool bJumpHandle = false;
			for (auto it : blocks)
			{
				if (jump == it.startPc)
				{
					bJumpHandle = true;
					break;
				}
			}

			if (bJumpHandle == false)
			{
				for (auto it = blocks.begin(); it != blocks.end(); ++it)
				{
					if (jump > it->startPc && jump <= it->endPc)
					{
						// Jump was into bb. Split bb.
						BBInfo bbBeforeJump;
						bbBeforeJump.startPc = it->startPc;
						bbBeforeJump.endPc = jump - 4;
						bbBeforeJump.isPseudoJump = true;

						it->startPc = jump;
						blocks.insert(it, bbBeforeJump);
						bJumpHandle = true;
						break;
					}
				}
			}

			if (bJumpHandle == false)
			{
				throw std::string("Jump wasn't handled! jump: " + std::to_string(jump));
			}
		}
	}

	func->bbinfo = blocks;
	/*for (auto it : blocks)
	{
		std::cout << std::hex << it.startPc << " " <<
			it.endPc << " " << it.isPseudoJump << std::endl;
	}
	std::cout << std::endl;*/
}

void Converter::createBranch(uint32_t jump, FINfo* func, uint32_t passBy, Value* cond)
{
	BasicBlock* jBlock = nullptr;
	BasicBlock* passBlock = nullptr;
	for (auto bb = func->bbinfo.begin(); bb != func->bbinfo.end(); ++bb)
	{
		if (jump == bb->startPc)
		{
			jBlock = bb->block;
			break;
		}
	}
	if (jBlock == nullptr)
	{
		throw std::string("Basic block wasn't found. Pc: " + std::to_string(jump));
	}
	
	if (cond)
	{
		for (auto bb = func->bbinfo.begin(); bb != func->bbinfo.end(); ++bb)
		{
			if (passBy == bb->startPc)
			{
				passBlock = bb->block;
				break;
			}
		}
		if (passBlock == nullptr)
		{
			throw std::string("Basic block wasn't found. Pc: " + std::to_string(passBy));
		}
	}

	if (cond)
	{
		builder->CreateCondBr(cond, jBlock, passBlock);
	}
	else
	{
		builder->CreateBr(jBlock);
	}
}

int Converter::getInstructionIdx(uint32_t pc) const
{
	int instIdx = -1;
	for (size_t i = 0; i < insts.size(); ++i)
	{
		if (insts[i].getPc() == pc)
		{
			instIdx = i;
			break;
		}
	}
	return instIdx;
}

void Converter::storeRegValue(Value* dst, uint32_t rd)
{
	if (rd != 0 && dst != nullptr)
	{
		Value* ptr = builder->CreateGEP(regFile, { getConstant(0), getConstant(rd) });
		builder->CreateStore(dst, ptr);
	}
}

Value* Converter::getRegValue(uint32_t n)
{
	if (n > 31)
	{
		throw std::string("Invalid register number!");
	}

	Value* ptr = builder->CreateGEP(regFile, { getConstant(0), getConstant(n) });
	return builder->CreateLoad(ptr);
}

llvm::Value* Converter::getConstant(uint32_t imm)
{
	return ConstantInt::get(Type::getInt32Ty(*context), std::to_string(imm), 10);
}

llvm::Function* Converter::createFunction(const std::string& name)
{
	Function* f = Function::Create(fType, Function::ExternalLinkage, name, module.get());
	f->getArg(0)->setName("pBuff");
	return f;
}

#pragma warning(pop)