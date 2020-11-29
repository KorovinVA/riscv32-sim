#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <iostream>
#include <map>
#include <iomanip>

#include "memory.h"

namespace ISA
{
    enum class OP
    {
        JAL,
        JALR,
        AUIPC,
        ADDI,
        ANDI,
        LW,
        SUB,
        SRLI,
        INVALID
    };

    enum class TYPE
    {
        R,
        I,
        S,
        B,
        U,
        J,
        INVALID
    };
}

class Instruction
{
public:
    Instruction();
    Instruction(uint32_t raw, uint32_t pc);
    ~Instruction();

    std::string getName() const;
    uint32_t    getImm()  const;
    uint32_t    getRd()   const;
    uint32_t    getRs1()  const;
    uint32_t    getRs2()  const;
    ISA::OP     getOp()   const;
    std::string getRName(uint32_t reg) const;
    void (*process)(Memory*, Instruction*) = nullptr;

    uint32_t operator() (const uint32_t end, const uint32_t start) const;
private:
    uint32_t    getBits(uint32_t raw, uint32_t end, uint32_t start) const;
    void        extendImm(uint8_t signBit);

    ISA::OP opcode;
    ISA::TYPE type;

    uint32_t data;
    uint32_t rd  = 0;
    uint32_t rs1 = 0;
    uint32_t rs2 = 0;
    uint32_t imm = 0;
    const uint32_t pc  = 0;

    const static std::map<uint32_t, std::string> rmap;
    std::stringstream name;
};

#endif //INSTRUCTION_H