#include "../inc/parser.h"

Parser::Parser(const std::string& elfFile):
	elf(elfFile)
{
	uint64_t imageSize = elf.getImageSize();
	data = new uint8_t[imageSize];
	elf.load(data);
	entryP = elf.getEntryPoint();

	disasm.open("disasm.asm");
}

std::vector<ISA::Instruction> Parser::parse()
{
	auto text = elf.execSections.front();

	uint64_t pc = 0;
	uint32_t* intData = (uint32_t*)data;
	disasm << text.name << "\n";

	for (pc = entryP / 4; pc <= END_ADDRESS / 4; ++pc)
	{
		ISA::Instruction inst(*(intData + pc), pc * 4);
		instBuff.push_back(inst);

		disasm << inst.getName();
	}

	pc = EXIT_ADDRESS / 4;
	CreatePseudoExit(&instBuff, &pc, &disasm);

	pc = ABORT_ADDRESS / 4;
	CreatePseudoAbort(&instBuff, &pc, &disasm);

	return instBuff;
}

Parser::~Parser()
{
	disasm.close();
	delete[] data;
}

void Parser::CreatePseudoAbort(std::vector<ISA::Instruction>* instbuff, uint64_t* pc, std::ofstream* disasm)
{
	ISA::Instruction inst(EBREAK_OPCODE, *pc * 4);
	instBuff.push_back(inst);
	++(*pc);
	*disasm << inst.getName();
}

void Parser::CreatePseudoExit(std::vector<ISA::Instruction>* instbuff, uint64_t* pc, std::ofstream* disasm)
{
	ISA::Instruction inst(ECALL_OPCODE, *pc * 4);
	instBuff.push_back(inst);
	++(*pc);
	*disasm << inst.getName();
}

uint32_t Parser::getEntryPoint() const
{
	return uint32_t(entryP);
}

uint8_t* Parser::getElfData()
{
	return data;
}

uint32_t Parser::getImageSize() const
{
	return uint32_t(elf.getImageSize());
}
