#include "instruction.h"
#include "functions.h"

const std::map<uint32_t, std::string> Instruction::rmap =
{
    {0,  "r0"},
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

Instruction::Instruction()
{}

Instruction::Instruction(uint32_t raw, uint32_t pc) :
    name(),
    pc(pc)
{
    data = raw;
    name << std::hex << pc << "\t";

    if(getBits(data, 6, 0) == 0x6f)
    {
        opcode = ISA::OP::JAL;
        type   = ISA::TYPE::J;

        rd     = getBits(data, 11, 7);

        uint32_t imm0_10  = getBits(data, 30, 21) << 1;
        uint32_t imm11_11 = getBits(data, 20, 20);
        uint32_t imm19_12 = getBits(data, 19, 12);
        uint32_t imm20_20 = getBits(data, 19, 12);
        imm  = imm0_10 + (imm11_11 << 11) + (imm19_12 << 12) + (imm20_20 << 20);
        extendImm(19);

        process = &Func::JAL;

        name << "jal " << getRName(rd) << ", " << imm + pc;
    }
    else if(getBits(data, 6, 0) == 0x17)
    {
        opcode = ISA::OP::AUIPC;
        type   = ISA::TYPE::J;

        rd     = getBits(data, 11, 7);
        imm    = getBits(data, 31, 12);

        process = &Func::AUIPC;
        name << "auipc " << getRName(rd) << ", 0x" << (int)imm;
    }
    else if(getBits(data, 6, 0) == 0x67)
    {
        opcode = ISA::OP::JALR;
        type   = ISA::TYPE::I;

        rd   = getBits(data, 11, 7);;
        rs1  = getBits(data, 19, 15);
        imm  = getBits(data, 31, 20);
        extendImm(11);

        process = &Func::JALR;
        name << "jalr " << getRName(rd) << ", " << 
                getRName(rs1) << ", " << std::dec << (int)imm;
    }
    else if(getBits(data, 6, 0) == 0x13)
    {
        if(getBits(data, 14, 12) == 0x0)
        {
            opcode = ISA::OP::ADDI;
            type   = ISA::TYPE::I;

            rd     = getBits(data, 11, 7);
            rs1    = getBits(data, 19, 15);
            imm    = getBits(data, 31, 20);
            extendImm(11);

            process = &Func::ADDI;
            name << "addi " << getRName(rd) << ", " << 
                getRName(rs1) << ", " << std::dec << (int)imm;
        }
        else if(getBits(data, 14, 12) == 0x7)
        {
            opcode = ISA::OP::ANDI;
            type   = ISA::TYPE::I;

            rd     = getBits(data, 11, 7);
            rs1    = getBits(data, 19, 15);
            imm    = getBits(data, 31, 20);
            extendImm(11);

            process = &Func::ANDI;
            name << "andi " << getRName(rd) << ", " << 
                getRName(rs1) << ", " << std::dec << int(imm);
        }
        else
        {
            name << "Unkown Instruction: " + std::to_string(data);
            throw name.str();
        }
    }
    else if(getBits(data, 6, 0) == 0x3)
    {
        rd  = getBits(data, 11, 7);
        rs1 = getBits(data, 19, 15);
        imm = getBits(data, 31, 20);
        extendImm(11);
        type   = ISA::TYPE::I;

        if(getBits(data, 14, 12) == 0x2)
        {
            opcode = ISA::OP::LW;
            process = &Func::LW;

            name << "lw " << getRName(rd) << ", " << std::dec << (int)imm << "(" <<
                getRName(rs1) << ")";
        }
        else
        {
            name << "Unkown Load Instruction: " + std::to_string(getBits(data, 14, 12));
            throw name.str();
        }
    }
    else if(getBits(data, 6, 0) == 0x33)
    {
        rd  = getBits(data, 11, 7);
        rs1 = getBits(data, 19, 15);
        rs2 = getBits(data, 24, 20);
        type   = ISA::TYPE::S;

        if(getBits(data, 14, 12) == 0x0)
        {
            opcode = ISA::OP::SUB;
            process = &Func::SUB;

            name << "sub " << getRName(rd) << ", " << getRName(rs1) <<
                ", " << getRName(rs2);
        }
        else
        {
            name << "Unkown Instruction: " + std::to_string(data);
            throw name.str();
        }
    }
    else
    {
        name << "Unkown Instruction: " + std::to_string(data);
        throw name.str();
    }
}

std::string Instruction::getName() const
{
    return name.str();
}

uint32_t Instruction::getImm() const
{
    return imm;
}

uint32_t Instruction::getRd() const
{
    return rd;
}

uint32_t Instruction::getRs1() const
{
    return rs1;
}

uint32_t Instruction::getRs2() const
{
    return rs2;
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