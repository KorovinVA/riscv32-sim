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
        SR, // SLLI, SRLI, SRAI
        N // ECALL, EBREAK
    };

const std::map<uint32_t, std::string> RMAP =
{
    {0,  "zr"},
    {1,  "ra"},
    {2,  "sp"},
    {3,  "gp"},
    {4,  "tp"},
    {5,  "t0"},
    {6,  "t1"},
    {7,  "t2"},
    {8,  "s0"},
    {9,  "s1"},
    {10, "a0"},
    {11, "a1"},
    {12, "a2"},
    {12, "a2"},
    {13, "a3"},
    {14, "a4"},
    {15, "a5"},
    {16, "a6"},
    {16, "a7"},
    {17, "a8"},
    {18, "s2"},
    {19, "s3"},
    {19, "s3"},
    {20, "s4"},
    {21, "s5"},
    {22, "s6"},
    {23, "s7"},
    {24, "s8"},
    {25, "s9"},
    {26, "s10"},
    {27, "s11"},
    {28, "t3"},
    {29, "t4"},
    {30, "t5"},
    {31, "t6"}
};

class Instruction
{
public:
    Instruction(uint32_t raw, uint64_t pc);
    ~Instruction();

    std::string getName() const;
    ISA::OP     getOp()   const;
    ISA::TYPE   getType() const;
    std::string getRName(uint32_t reg) const;

    uint32_t getImm()  const;
    uint32_t getRd()   const;
    uint32_t getRs1()  const;
    uint32_t getRs2()  const;
    uint32_t getPc()   const;

    uint32_t operator() (const uint32_t end, const uint32_t start) const;
private:
    uint32_t getBits(uint32_t raw, uint32_t end, uint32_t start) const;
    void     extendImm(uint8_t signBit);

    ISA::OP opcode;
    ISA::TYPE type;

    uint32_t rd  = 0;
    uint32_t rs1 = 0;
    uint32_t rs2 = 0;
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
inline uint32_t Instruction::getPc() const
{
    return uint32_t(pc);
}
}
#endif //INSTRUCTION_H