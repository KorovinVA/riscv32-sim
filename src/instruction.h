#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <iostream>
#include <map>
#include <iomanip>
#include <sstream>

#include "memory.h"

namespace ISA
{
    enum class OP
    {
        LUI,
        JAL,
        JALR,
        AUIPC,
        BEQ,
        BNE,
        BLT,
        BLTU,
        BGE,
        BGEU,
        LW,
        LBU,
        SB,
        SW,
        ADDI,
        SLTIU,
        XORI,
        ANDI,
        SLLI,
        SRLI,
        SRAI,
        ADD,
        SUB,
        SLTU,
        OR,
        AND,
        MUL,
        DIVU,
        LRW,
        AMOSWAP,
        ECALL
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
    ISA::OP     getOp()   const;
    std::string getRName(uint32_t reg) const;
    void (*process)(Memory*, Instruction*) = nullptr;

    uint32_t getImm()  const;
    uint32_t getRd()   const;
    uint32_t getRs1()  const;
    uint32_t getRs2()  const;

    uint32_t operator() (const uint32_t end, const uint32_t start) const;
private:
    uint32_t getBits(uint32_t raw, uint32_t end, uint32_t start) const;
    void     extendImm(uint8_t signBit);

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


inline uint32_t Instruction::getImm()  const
{
    return imm;
}
inline uint32_t Instruction::getRd()   const
{
    return rd;
}
inline uint32_t Instruction::getRs1()  const
{
    return rs1;
}
inline uint32_t Instruction::getRs2()  const
{
    return rs2;
}

#endif //INSTRUCTION_H