#ifndef PARSER_H
#define PARSER_H

#include "instruction.h"
#include "readelf.h"
#include "macro.h"

class Parser
{
public:
    Parser(const std::string& elfFile, const std::string& output);
    std::vector<ISA::Instruction> parse();
    uint8_t* getElfData();
    uint32_t getImageSize() const;
    uint32_t getEntryPoint() const;
    ~Parser();
private:
    void CreatePseudoAbort(std::vector<ISA::Instruction>* instbuff, uint64_t* pc, std::ofstream* disasm);
    void CreatePseudoExit(std::vector<ISA::Instruction>* instbuff, uint64_t* pc, std::ofstream* disasm);

    uint64_t entryP = 0;
    uint8_t* data = nullptr;
    ElfReader elf;
    std::vector<ISA::Instruction> instBuff;
    std::ofstream disasm;
};

#endif //PARSER_H
