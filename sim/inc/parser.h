#ifndef PARSER_H
#define PARSER_H

#include "instruction.h"
#include "readelf.h"

class Parser
{
public:
    Parser(const std::string& elfFile);
    std::vector<ISA::Instruction> parse();
    uint8_t* getElfData();
    uint32_t getImageSize() const;
    ~Parser();
private:
    void CreatePseudoAbort(std::vector<ISA::Instruction>* instbuff, uint64_t* pc, std::ofstream* disasm);
    void CreatePseudoExit(std::vector<ISA::Instruction>* instbuff, uint64_t* pc, std::ofstream* disasm);
    uint32_t getEntryPoint() const;

    uint32_t EBREAK = 0x00100073;
    uint32_t ECALL  = 0x00000073;
    uint64_t entryP = 0;
    uint32_t endP   = 0x10780;
    uint64_t exitP  = 0x109bc;

    uint8_t* data = nullptr;
    ElfReader elf;
    std::vector<ISA::Instruction> instBuff;
    std::ofstream disasm;
};

#endif //PARSER_H