#include "../inc/parser.h"

Parser::Parser(const std::string& elfFile):
	elf(elfFile)
{
	uint64_t imageSize = elf.getImageSize();
	data = new uint8_t[imageSize];
	elf.load(data);
}

void Parser::parse()
{
	for (auto it : elf.execSections)
	{
		uint64_t pc = it.addr / 4;
		uint64_t block = (it.addr + it.size) / 4;
		uint32_t* intData = (uint32_t*)data;
		for (; pc < block; ++pc)
		{
			Instruction inst(*(intData + pc), pc * 4);
			instBuff.push_back(inst);
		}
	}
}

Parser::~Parser()
{
	delete[] data;
}
