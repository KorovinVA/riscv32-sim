#ifndef PARSER_H
#define PARSER_H

#include "instruction.h"
#include "readelf.h"

class Parser
{
public:
    Parser(const std::string& elfFile);
    void parse();
    ~Parser();
private:
    uint8_t* data = nullptr;
    ElfReader elf;
    std::vector<Instruction> instBuff;
    std::ofstream disasm;
};

#endif //PARSER_H