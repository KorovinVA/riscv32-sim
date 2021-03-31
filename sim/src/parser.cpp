#include "../inc/parser.h"

Parser::Parser(const std::string& elfFile):
	elf(elfFile)
{
	uint64_t imageSize = elf.getImageSize();
	data = new uint8_t[imageSize];
	elf.load(data);
	entryP = elf.getEntryPoint();

	disasm.open("D:/Users/vkorovin/riscv32-sim/disasm.asm");
}

std::vector<ISA::Instruction> Parser::parse()
{
	auto text = elf.execSections.front();

	uint64_t pc = 0;
	uint32_t* intData = (uint32_t*)data;
	disasm << text.name << "\n";

	for (pc = entryP / 4; pc <= endP / 4; ++pc)
	{
		ISA::Instruction inst(*(intData + pc), pc * 4);
		instBuff.push_back(inst);

		disasm << inst.getName();
	}

	pc = exitP / 4;
	CreatePseudoExit(&instBuff, &pc, &disasm);
	pc = text.addr / 4;
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
	ISA::Instruction inst(EBREAK, *pc * 4);
	instBuff.push_back(inst);
	++(*pc);
	*disasm << inst.getName();
}

void Parser::CreatePseudoExit(std::vector<ISA::Instruction>* instbuff, uint64_t* pc, std::ofstream* disasm)
{
	ISA::Instruction inst(ECALL, *pc * 4);
	instBuff.push_back(inst);
	++(*pc);
	*disasm << inst.getName();
}

uint32_t Parser::getEntryPoint() const
{
	return uint32_t(entryP);
}
