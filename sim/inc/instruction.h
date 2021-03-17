#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>

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
        BGE,
        BLTU,
        BGEU,
        LB,
        LH,
        LW,
        LBU,
        LHU,
        SB,
        SH,
        SW,
        ADDI,
        SLTI,
        SLTIU,
        XORI,
        ORI,
        ANDI,
        SLLI,
        SRLI,
        SRAI,
        ADD,
        SUB,
        SLL,
        SLT,
        SLTU,
        XOR,
        SRL,
        SRA,
        OR,
        AND,
        FENCE,
        ECALL,
        EBREAK,
        MUL,
        MULH,
        MULHSU,
        MULHU,
        DIV,
        DIVU,
        REM,
        REMU,
        LR_W,
        SC_W,
        AMOSWAP_W,
        AMOADD_W,
        AMOXOR_W,
        AMOAND_W,
        AMOOR_W,
        AMOMIN_W,
        AMOMAX_W,
        AMOMINU_W,
        AMOMAXU_W,
        CSRRW,
        CSRRS,
        CSRRSI,
        FLD,
        FSD,
        FSGNJX_D,
        FEQ_D,
        FLT_D
    };

    enum class TYPE
    {
        R,
        I,
        S,
        B,
        U,
        J,
        SR // SLLI, SRLI, SRAI
    };
}

class Instruction
{
public:
    Instruction(uint32_t raw, uint64_t pc);
    ~Instruction();

    std::string getName() const;
    ISA::OP     getOp()   const;
    std::string getRName(uint32_t reg) const;

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

    uint32_t rd   = 0;
    uint32_t rs1  = 0;
    uint32_t rs2  = 0;
    uint32_t imm = 0;
    const uint64_t pc  = 0;
    const uint32_t data = 0;

    std::string isaText;
    std::string name;

    bool isParsed = false;
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