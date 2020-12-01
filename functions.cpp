#include "functions.h"

void Func::JAL(Memory* mem, Instruction* insn)
{
    mem->setReg(insn->getRd(), mem->getPc() + 4);
    mem->setPc(mem->getPc() + insn->getImm());
}

void Func::AUIPC(Memory* mem, Instruction* insn)
{
    uint32_t nPc = mem->getPc() + (insn->getImm() << 12);
    mem->setReg(insn->getRd(), nPc);
    mem->setPc(mem->getPc() + 4);
}

void Func::ADDI(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) + insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}

void Func::ANDI(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) & insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}

void Func::JALR(Memory* mem, Instruction* insn)
{
    uint32_t jump = mem->getReg(insn->getRs1()) + insn->getImm();
    jump <<= 1;
    jump >>= 1;
    
    mem->setReg(insn->getRd(), mem->getPc() + 4);
    mem->setPc(jump);
}

void Func::LW(Memory* mem, Instruction* insn)
{
    uint32_t addr = insn->getImm() + mem->getReg(insn->getRs1());
    mem->setReg(insn->getRd(), mem->load(addr, 4));
    mem->setPc(mem->getPc() + 4);
}

void Func::SUB(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) - mem->getReg(insn->getRs2());
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}

void Func::SRLI(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) >> insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}

void Func::SW(Memory* mem, Instruction* insn)
{
    uint32_t addr = insn->getImm() + mem->getReg(insn->getRs1());
    mem->store(addr, mem->getReg(insn->getRs2()), 4);
    mem->setPc(mem->getPc() + 4);
}

void Func::LUI(Memory* mem, Instruction* insn)
{
    uint32_t res = insn->getImm() << 12;
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}

void Func::BEQ(Memory* mem, Instruction* insn)
{
    if(mem->getReg(insn->getRs1()) == mem->getReg(insn->getRs2()))
    {
        mem->setPc(mem->getPc() + insn->getImm());
    }
    else
    {
        mem->setPc(mem->getPc() + 4);
    }
}

void Func::SLLI(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) << insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}

void Func::ADD(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) + mem->getReg(insn->getRs2());
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}

void Func::BNE(Memory* mem, Instruction* insn)
{
    if(mem->getReg(insn->getRs1()) != mem->getReg(insn->getRs2()))
    {
        mem->setPc(mem->getPc() + insn->getImm());
    }
    else
    {
        mem->setPc(mem->getPc() + 4);
    }
}

void Func::ECALL(Memory* mem, Instruction* insn)
{
    mem->setPc(mem->getPc() + 4);
}

void Func::SLTU(Memory* mem, Instruction* insn)
{
    if(mem->getReg(insn->getRs1()) < mem->getReg(insn->getRs2()))
    {
        mem->setReg(insn->getRd(), 1);
    }
    else
    {
        mem->setReg(insn->getRd(), 0);
    }
    mem->setPc(mem->getPc() + 4);
}

void Func::BGEU(Memory* mem, Instruction* insn)
{
    if(mem->getReg(insn->getRs1()) >= mem->getReg(insn->getRs2()))
    {
        mem->setPc(mem->getPc() + insn->getImm());
    }
    else
    {
        mem->setPc(mem->getPc() + 4);
    }
}

void Func::BLTU(Memory* mem, Instruction* insn)
{
    if(mem->getReg(insn->getRs1()) < mem->getReg(insn->getRs2()))
    {
        mem->setPc(mem->getPc() + insn->getImm());
    }
    else
    {
        mem->setPc(mem->getPc() + 4);
    }
}

void Func::DIVU(Memory* mem, Instruction* insn)
{
    if(mem->getReg(insn->getRs2()) == 0)
    {
        mem->setReg(insn->getRd(), uint32_t(-1));
    }
    else
    {
        uint32_t res = mem->getReg(insn->getRs1()) / mem->getReg(insn->getRs2());
        mem->setReg(insn->getRd(), res);
    }
    mem->setPc(mem->getPc() + 4);
}

void Func::MUL(Memory* mem, Instruction* insn)
{
    uint64_t res = (uint64_t)mem->getReg(insn->getRs1()) * (uint64_t)mem->getReg(insn->getRs2());
    mem->setReg(insn->getRd(), (uint32_t)res);
    mem->setPc(mem->getPc() + 4);
}

void Func::BLT(Memory* mem, Instruction* insn)
{
    if((int)mem->getReg(insn->getRs1()) < (int)mem->getReg(insn->getRs2()))
    {
        mem->setPc(mem->getPc() + insn->getImm());
    }
    else
    {
        mem->setPc(mem->getPc() + 4);
    }
}

void Func::BGE(Memory* mem, Instruction* insn)
{
    if((int)mem->getReg(insn->getRs1()) >= (int)mem->getReg(insn->getRs2()))
    {
        mem->setPc(mem->getPc() + insn->getImm());
    }
    else
    {
        mem->setPc(mem->getPc() + 4);
    }
}

void Func::AND(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) & mem->getReg(insn->getRs2());
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}

void Func::LBU(Memory* mem, Instruction* insn)
{
    uint32_t addr = insn->getImm() + mem->getReg(insn->getRs1());
    mem->setReg(insn->getRd(), mem->load(addr, 1));
    mem->setPc(mem->getPc() + 4);
}

void Func::SB(Memory* mem, Instruction* insn)
{
    uint32_t addr = insn->getImm() + mem->getReg(insn->getRs1());
    mem->store(addr, mem->getReg(insn->getRs2()), 1);
    mem->setPc(mem->getPc() + 4);
}

void Func::OR(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) | mem->getReg(insn->getRs2());
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}

void Func::XORI(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) ^ insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->setPc(mem->getPc() + 4);
}

void Func::AMOSWAP(Memory* mem, Instruction* insn)
{
    //Not atomic
    uint32_t addr = mem->getReg(insn->getRs1());
    uint32_t val  = mem->load(addr, 4);
    mem->setReg(insn->getRd(), val);

    uint32_t temp = mem->getReg(insn->getRs2());
    mem->setReg(insn->getRs2(), val);
    val = temp;

    mem->store(addr, val, 4);
    mem->setPc(mem->getPc() + 4);
}