#include "../inc/instruction.h"

const static std::map<uint32_t, std::string> rmap =
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

const static std::vector<std::tuple<uint32_t, uint32_t, uint32_t, std::string>> instmap =
{
    // RV32I Base Instruction Set
    {ISA::OP::LUI,    0x7f,       0x37,       "lui"},
    {ISA::OP::AUIPC,  0x7f,       0x17,       "auipc"},
    {ISA::OP::JAL,    0x7f,       0x6f,       "jal"},
    {ISA::OP::JALR,   0x707f,     0x67,       "jalr"},
    {ISA::OP::BEQ,    0x707f,     0x63,       "beq"},
    {ISA::OP::BNE,    0x707f,     0x1063,     "bne"},
    {ISA::OP::BLT,    0x707f,     0x4063,     "blt"},
    {ISA::OP::BGE,    0x707f,     0x5063,     "bge"},
    {ISA::OP::BLTU,   0x707f,     0x6063,     "bltu"},
    {ISA::OP::BGEU,   0x707f,     0x7063,     "bgeu"},
    {ISA::OP::LB,     0x707f,     0x3,        "lb"},
    {ISA::OP::LH,     0x707f,     0x1003,     "lh"},
    {ISA::OP::LW,     0x707f,     0x2003,     "lw"},
    {ISA::OP::LBU,    0x707f,     0x4003,     "lbu"},
    {ISA::OP::LHU,    0x707f,     0x5003,     "lhu"},
    {ISA::OP::SB,     0x707f,     0x23,       "sb"},
    {ISA::OP::SH,     0x707f,     0x1023,     "sh"},
    {ISA::OP::SW,     0x707f,     0x2023,     "sw"},
    {ISA::OP::ADDI,   0x707f,     0x13,       "addi"},
    {ISA::OP::SLTI,   0x707f,     0x2013,     "slti"},
    {ISA::OP::SLTIU,  0x707f,     0x3013,     "sltiu"},
    {ISA::OP::XORI,   0x707f,     0x4013,     "xori"},
    {ISA::OP::ORI,    0x707f,     0x6013,     "ori"},
    {ISA::OP::ANDI,   0x707f,     0x7013,     "andi"},
    {ISA::OP::SLLI,   0xfe00707f, 0x1013,     "slli"},
    {ISA::OP::SRLI,   0xfe00707f, 0x5013,     "srli"},
    {ISA::OP::SRAI,   0xfe00707f, 0x40005013, "srai"},
    {ISA::OP::ADD,    0xfe00707f, 0x33,       "add"},
    {ISA::OP::SLL,    0xfe00707f, 0x1033,     "sll"},
    {ISA::OP::SLT,    0xfe00707f, 0x2033,     "slt"},
    {ISA::OP::SLTU,   0xfe00707f, 0x3033,     "sltu"},
    {ISA::OP::XOR,    0xfe00707f, 0x4033,     "xor"},
    {ISA::OP::SRL,    0xfe00707f, 0x5033,     "srl"},
    {ISA::OP::SRA,    0xfe00707f, 0x40005033, "sra"},
    {ISA::OP::OR,     0xfe00707f, 0x6033,     "or"},
    {ISA::OP::AND,    0xfe00707f, 0x7033,     "and"},
    {ISA::OP::FENCE,  0x707f,     0xf,        "fence"},
    {ISA::OP::ECALL,  0xffffffff, 0x73,       "ecall"},
    {ISA::OP::EBREAK, 0xffffffff, 0x100073,   "ebreak"},

    // RV32M Standard Extension
    {ISA::OP::MUL,    0xfe00707f, 0x2000033, "mul"},
    {ISA::OP::MULH,   0xfe00707f, 0x2001033, "mulh"},
    {ISA::OP::MULHSU, 0xfe00707f, 0x2002033, "mulhsu"},
    {ISA::OP::MULHU,  0xfe00707f, 0x2003033, "mulhu"},
    {ISA::OP::DIV,    0xfe00707f, 0x2004033, "div"},
    {ISA::OP::DIVU,   0xfe00707f, 0x2005033, "divu"},
    {ISA::OP::REM,    0xfe00707f, 0x2006033, "rem"},
    {ISA::OP::REMU,   0xfe00707f, 0x2007033, "remu"},

    // RV32A Standard Extension
    {ISA::OP::LR_W,      0xf9f0707f, 0x1000202f, "lr.w"},
    {ISA::OP::SC_W,      0xf800707f, 0x1800202f, "sc.w"},
    {ISA::OP::AMOSWAP_W, 0xf800707f, 0x800202f,  "amoswap.w"},
    {ISA::OP::AMOADD_W,  0xf800707f, 0x202f,     "amoadd.w"},
    {ISA::OP::AMOXOR_W,  0xf800707f, 0x2000202f, "amoxor.w"},
    {ISA::OP::AMOAND_W,  0xf800707f, 0x6000202f, "amoand.w"},
    {ISA::OP::AMOOR_W,   0xf800707f, 0x4000202f, "amoor.w"},
    {ISA::OP::AMOMIN_W,  0xf800707f, 0x8000202f, "amomin.w"},
    {ISA::OP::AMOMAX_W,  0xf800707f, 0xa000202f, "amomax.w"},
    {ISA::OP::AMOMINU_W, 0xf800707f, 0xc000202f, "amominu.w"},
    {ISA::OP::AMOMAXU_W, 0xf800707f, 0xe000202f, "amomaxu.w"},
};

Instruction::Instruction(uint32_t raw, uint64_t pc) :
    isaText(),
    pc(pc)
{
    ;
}

std::string Instruction::getName() const
{
    return isaText;
}

ISA::OP Instruction::getOp() const
{
    return opcode;
}

uint32_t Instruction::operator() (const uint32_t end, const uint32_t start) const
{
    return getBits(data, end, start);
}


uint32_t Instruction::getBits(uint32_t raw, uint32_t end, uint32_t start) const
{
    raw = raw << (31 - end);
    raw = raw >> (31 - end);
    raw = raw >> start;
    return raw;
}

void Instruction::extendImm(uint8_t signBit)
{
    if(getBits(imm, signBit, signBit) == 1)
    {
        imm |= (0xffffffff << (signBit + 1));
    }
}

std::string Instruction::getRName(uint32_t reg) const
{
    std::map<uint32_t, std::string>::const_iterator it = rmap.find(reg);
    if (it == rmap.end())
    {
        throw "No such register";
    } 

    return it->second;
}

Instruction::~Instruction()
{}