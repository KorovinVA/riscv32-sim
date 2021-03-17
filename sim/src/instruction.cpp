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

const static std::vector<std::tuple<ISA::OP, uint32_t, uint32_t, std::string, ISA::TYPE>> instBasic
{
    // RV32I Base Instruction Set
    {ISA::OP::LUI,    0x7f,       0x37,       "lui",    ISA::TYPE::U},
    {ISA::OP::AUIPC,  0x7f,       0x17,       "auipc",  ISA::TYPE::U},
    {ISA::OP::JAL,    0x7f,       0x6f,       "jal",    ISA::TYPE::J},
    {ISA::OP::JALR,   0x707f,     0x67,       "jalr",   ISA::TYPE::I},
    {ISA::OP::BEQ,    0x707f,     0x63,       "beq",    ISA::TYPE::B},
    {ISA::OP::BNE,    0x707f,     0x1063,     "bne",    ISA::TYPE::B},
    {ISA::OP::BLT,    0x707f,     0x4063,     "blt",    ISA::TYPE::B},
    {ISA::OP::BGE,    0x707f,     0x5063,     "bge",    ISA::TYPE::B},
    {ISA::OP::BLTU,   0x707f,     0x6063,     "bltu",   ISA::TYPE::B},
    {ISA::OP::BGEU,   0x707f,     0x7063,     "bgeu",   ISA::TYPE::B},
    {ISA::OP::LB,     0x707f,     0x3,        "lb",     ISA::TYPE::I},
    {ISA::OP::LH,     0x707f,     0x1003,     "lh",     ISA::TYPE::I},
    {ISA::OP::LW,     0x707f,     0x2003,     "lw",     ISA::TYPE::I},
    {ISA::OP::LBU,    0x707f,     0x4003,     "lbu",    ISA::TYPE::I},
    {ISA::OP::LHU,    0x707f,     0x5003,     "lhu",    ISA::TYPE::I},
    {ISA::OP::SB,     0x707f,     0x23,       "sb",     ISA::TYPE::S},
    {ISA::OP::SH,     0x707f,     0x1023,     "sh",     ISA::TYPE::S},
    {ISA::OP::SW,     0x707f,     0x2023,     "sw",     ISA::TYPE::S},
    {ISA::OP::ADDI,   0x707f,     0x13,       "addi",   ISA::TYPE::I},
    {ISA::OP::SLTI,   0x707f,     0x2013,     "slti",   ISA::TYPE::I},
    {ISA::OP::SLTIU,  0x707f,     0x3013,     "sltiu",  ISA::TYPE::I},
    {ISA::OP::XORI,   0x707f,     0x4013,     "xori",   ISA::TYPE::I},
    {ISA::OP::ORI,    0x707f,     0x6013,     "ori",    ISA::TYPE::I},
    {ISA::OP::ANDI,   0x707f,     0x7013,     "andi",   ISA::TYPE::I},
    {ISA::OP::SLLI,   0xfe00707f, 0x1013,     "slli",   ISA::TYPE::SR},
    {ISA::OP::SRLI,   0xfe00707f, 0x5013,     "srli",   ISA::TYPE::SR},
    {ISA::OP::SRAI,   0xfe00707f, 0x40005013, "srai",   ISA::TYPE::SR},
    {ISA::OP::ADD,    0xfe00707f, 0x33,       "add",    ISA::TYPE::R},
    {ISA::OP::SUB,    0xfe00707f, 0x40000033, "sub",    ISA::TYPE::R},
    {ISA::OP::SLL,    0xfe00707f, 0x1033,     "sll",    ISA::TYPE::R},
    {ISA::OP::SLT,    0xfe00707f, 0x2033,     "slt",    ISA::TYPE::R},
    {ISA::OP::SLTU,   0xfe00707f, 0x3033,     "sltu",   ISA::TYPE::R},
    {ISA::OP::XOR,    0xfe00707f, 0x4033,     "xor",    ISA::TYPE::R},
    {ISA::OP::SRL,    0xfe00707f, 0x5033,     "srl",    ISA::TYPE::R},
    {ISA::OP::SRA,    0xfe00707f, 0x40005033, "sra",    ISA::TYPE::R},
    {ISA::OP::OR,     0xfe00707f, 0x6033,     "or",     ISA::TYPE::R},
    {ISA::OP::AND,    0xfe00707f, 0x7033,     "and",    ISA::TYPE::R},
    {ISA::OP::FENCE,  0x707f,     0xf,        "fence",  ISA::TYPE::I},
    {ISA::OP::ECALL,  0xffffffff, 0x73,       "ecall",  ISA::TYPE::I},
    {ISA::OP::EBREAK, 0xffffffff, 0x100073,   "ebreak", ISA::TYPE::I},

    // RV32M Standard Extension
    {ISA::OP::MUL,    0xfe00707f, 0x2000033, "mul",    ISA::TYPE::R},
    {ISA::OP::MULH,   0xfe00707f, 0x2001033, "mulh",   ISA::TYPE::R},
    {ISA::OP::MULHSU, 0xfe00707f, 0x2002033, "mulhsu", ISA::TYPE::R},
    {ISA::OP::MULHU,  0xfe00707f, 0x2003033, "mulhu",  ISA::TYPE::R},
    {ISA::OP::DIV,    0xfe00707f, 0x2004033, "div",    ISA::TYPE::R},
    {ISA::OP::DIVU,   0xfe00707f, 0x2005033, "divu",   ISA::TYPE::R},
    {ISA::OP::REM,    0xfe00707f, 0x2006033, "rem",    ISA::TYPE::R},
    {ISA::OP::REMU,   0xfe00707f, 0x2007033, "remu",   ISA::TYPE::R},

    // RV32A Standard Extension
    {ISA::OP::LR_W,      0xf9f0707f, 0x1000202f, "lr.w",      ISA::TYPE::R},
    {ISA::OP::SC_W,      0xf800707f, 0x1800202f, "sc.w",      ISA::TYPE::R},
    {ISA::OP::AMOSWAP_W, 0xf800707f, 0x800202f,  "amoswap.w", ISA::TYPE::R},
    {ISA::OP::AMOADD_W,  0xf800707f, 0x202f,     "amoadd.w" , ISA::TYPE::R},
    {ISA::OP::AMOXOR_W,  0xf800707f, 0x2000202f, "amoxor.w",  ISA::TYPE::R},
    {ISA::OP::AMOAND_W,  0xf800707f, 0x6000202f, "amoand.w",  ISA::TYPE::R},
    {ISA::OP::AMOOR_W,   0xf800707f, 0x4000202f, "amoor.w",   ISA::TYPE::R},
    {ISA::OP::AMOMIN_W,  0xf800707f, 0x8000202f, "amomin.w",  ISA::TYPE::R},
    {ISA::OP::AMOMAX_W,  0xf800707f, 0xa000202f, "amomax.w",  ISA::TYPE::R},
    {ISA::OP::AMOMINU_W, 0xf800707f, 0xc000202f, "amominu.w", ISA::TYPE::R},
    {ISA::OP::AMOMAXU_W, 0xf800707f, 0xe000202f, "amomaxu.w", ISA::TYPE::R},

    // RV32/RV64 Zicsr Standard Extension
    {ISA::OP::CSRRW,  0x707f, 0x1073, "csrrw",  ISA::TYPE::I},
    {ISA::OP::CSRRS,  0x707f, 0x2073, "csrrs",  ISA::TYPE::I},
    {ISA::OP::CSRRSI, 0x707f, 0x6073, "csrrsi", ISA::TYPE::I},

    // RV32D Standard Extension
    {ISA::OP::FLD,      0x707f,     0x3007,     "fld",      ISA::TYPE::I},
    {ISA::OP::FSD,      0x707f,     0x3027,     "fsd",      ISA::TYPE::S},
    {ISA::OP::FSGNJX_D, 0xfe00707f, 0x22002053, "fsgnjx.d", ISA::TYPE::R},
    {ISA::OP::FEQ_D,    0xfe00707f, 0xa2002053, "feq.d",    ISA::TYPE::R},
    {ISA::OP::FLT_D,    0xfe00707f, 0xa2001053, "flt.d",    ISA::TYPE::R}
};

Instruction::Instruction(uint32_t raw, uint64_t pc) :
    isaText(),
    pc(pc),
    data(raw)
{
    for (auto it : instBasic)
    {
        if ((data & std::get<1>(it)) == std::get<2>(it))
        {
            isParsed = true;
            opcode = std::get<0>(it);
            type = std::get<4>(it);
            name = std::get<3>(it);
            break;
        }
    }

    if (!isParsed)
    {
        std::stringstream excp;
        excp << "Unknown instruction:\n";
        excp << std::hex << "0x" << pc << " : " << "0x" << data;
        throw excp.str();
    }

    std::stringstream sstream;
    sstream << std::hex << pc << ":\t";
    switch (type)
    {
    case ISA::TYPE::R:
        rd = getBits(data, 11, 7);
        rs1 = getBits(data, 19, 15);
        rs2 = getBits(data, 24, 20);
        sstream << name << " " << getRName(rd) << "," <<
            getRName(rs1) << "," << getRName(rs2) << "\n";
        break;
    case ISA::TYPE::I:
        rd = getBits(data, 11, 7);
        rs1 = getBits(data, 19, 15);
        imm = getBits(data, 31, 20);
        extendImm(11);
        sstream << name << " " << getRName(rd) << "," <<
            getRName(rs1) << "," << std::dec << (int)imm << "\n";
        break;
    case ISA::TYPE::S:
    {
        rs1 = getBits(data, 19, 15);
        rs2 = getBits(data, 24, 20);

        uint32_t imm4_0 = getBits(data, 11, 7);
        uint32_t imm11_5 = getBits(data, 31, 25);

        imm = imm4_0 + (imm11_5 << 5);
        extendImm(11);

        sstream << name << " " << getRName(rs2) << "," << std::dec << (int)imm << "(" <<
            getRName(rs1) << ")" << "\n";
        break;
    }
    case ISA::TYPE::B:
    {
        rs1 = getBits(data, 19, 15);
        rs2 = getBits(data, 24, 20);

        uint32_t imm4_1 = getBits(data, 11, 8);
        uint32_t imm10_5 = getBits(data, 30, 25);
        uint32_t imm11 = getBits(data, 7, 7);
        uint32_t imm12 = getBits(data, 31, 31);

        imm = (imm4_1 << 1) + (imm10_5 << 5) + (imm11 << 11) + (imm12 << 12);
        extendImm(12);

        sstream << name << " " << getRName(rs1) <<
            "," << getRName(rs2) << "," << pc + imm << "\n";
        break;
    }
    case ISA::TYPE::U:
        rd = getBits(data, 11, 7);
        imm = getBits(data, 31, 12);
        sstream << name << " " << getRName(rd) << ",0x" << (int)imm << "\n";
        break;
    case::ISA::TYPE::J:
    {
        rd = getBits(data, 11, 7);

        uint32_t imm0_10 = getBits(data, 30, 21) << 1;
        uint32_t imm11_11 = getBits(data, 20, 20);
        uint32_t imm19_12 = getBits(data, 19, 12);
        uint32_t imm20_20 = getBits(data, 31, 31);
        imm = imm0_10 + (imm11_11 << 11) + (imm19_12 << 12) + (imm20_20 << 20);

        extendImm(20);
        sstream << name << " " << getRName(rd) << "," << imm + pc << "\n";
        break;
    }
    case::ISA::TYPE::SR:
        rd = getBits(data, 11, 7);
        rs1 = getBits(data, 19, 15);
        imm = getBits(data, 24, 20);

        sstream << name << " " << getRName(rd) << "," <<
            getRName(rs1) << ",0x" << imm << "\n";
        break;
    default:
        throw std::string("Unknown instruction type!");
    }

    isaText = sstream.str();
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