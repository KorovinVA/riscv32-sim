#include "../inc/functions.h"

void Func::JAL(Memory* mem, Instruction* insn)
{
    mem->setReg(insn->getRd(), mem->getPc() + 4);
    mem->setPc(mem->getPc() + insn->getImm());
}

void Func::AUIPC(Memory* mem, Instruction* insn)
{
    uint32_t nPc = mem->getPc() + (insn->getImm() << 12);
    mem->setReg(insn->getRd(), nPc);
    mem->updatePc();
}

void Func::ADDI(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) + insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->updatePc();
}

void Func::ANDI(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) & insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->updatePc();
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
    mem->setReg(insn->getRd(), mem->loadWord(addr));
    mem->updatePc();
}

void Func::SUB(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) - mem->getReg(insn->getRs2());
    mem->setReg(insn->getRd(), res);
    mem->updatePc();
}

void Func::SRLI(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) >> insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->updatePc();
}

void Func::SW(Memory* mem, Instruction* insn)
{
    uint32_t addr = insn->getImm() + mem->getReg(insn->getRs1());
    mem->storeWord(addr, mem->getReg(insn->getRs2()));
    mem->updatePc();
}

void Func::LUI(Memory* mem, Instruction* insn)
{
    uint32_t res = insn->getImm() << 12;
    mem->setReg(insn->getRd(), res);
    mem->updatePc();
}

void Func::BEQ(Memory* mem, Instruction* insn)
{
    if(mem->getReg(insn->getRs1()) == mem->getReg(insn->getRs2()))
    {
        mem->setPc(mem->getPc() + insn->getImm());
    }
    else
    {
        mem->updatePc();
    }
}

void Func::SLLI(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) << insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->updatePc();
}

void Func::ADD(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) + mem->getReg(insn->getRs2());
    mem->setReg(insn->getRd(), res);
    mem->updatePc();
}

void Func::BNE(Memory* mem, Instruction* insn)
{
    if(mem->getReg(insn->getRs1()) != mem->getReg(insn->getRs2()))
    {
        mem->setPc(mem->getPc() + insn->getImm());
    }
    else
    {
        mem->updatePc();
    }
}

void Func::ECALL(Memory* mem, Instruction* insn)
{
    //Programm ends here
    throw -1;
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
    mem->updatePc();
}

void Func::BGEU(Memory* mem, Instruction* insn)
{
    if(mem->getReg(insn->getRs1()) >= mem->getReg(insn->getRs2()))
    {
        mem->setPc(mem->getPc() + insn->getImm());
    }
    else
    {
        mem->updatePc();
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
        mem->updatePc();
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
    mem->updatePc();
}

void Func::MUL(Memory* mem, Instruction* insn)
{
    uint64_t res = (uint64_t)mem->getReg(insn->getRs1()) * (uint64_t)mem->getReg(insn->getRs2());
    mem->setReg(insn->getRd(), (uint32_t)res);
    mem->updatePc();
}

void Func::BLT(Memory* mem, Instruction* insn)
{
    if((int)mem->getReg(insn->getRs1()) < (int)mem->getReg(insn->getRs2()))
    {
        mem->setPc(mem->getPc() + insn->getImm());
    }
    else
    {
        mem->updatePc();
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
        mem->updatePc();
    }
}

void Func::AND(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) & mem->getReg(insn->getRs2());
    mem->setReg(insn->getRd(), res);
    mem->updatePc();
}

void Func::LBU(Memory* mem, Instruction* insn)
{
    uint32_t addr = insn->getImm() + mem->getReg(insn->getRs1());
    mem->setReg(insn->getRd(), mem->loadByte(addr));
    mem->updatePc();
}

void Func::SB(Memory* mem, Instruction* insn)
{
    uint32_t addr = insn->getImm() + mem->getReg(insn->getRs1());
    mem->storeByte(addr, mem->getReg(insn->getRs2()));
    mem->updatePc();
}

void Func::OR(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) | mem->getReg(insn->getRs2());
    mem->setReg(insn->getRd(), res);
    mem->updatePc();
}

void Func::XORI(Memory* mem, Instruction* insn)
{
    uint32_t res = mem->getReg(insn->getRs1()) ^ insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->updatePc();
}

void Func::AMOSWAP(Memory* mem, Instruction* insn)
{
    //Not atomic
    uint32_t addr = mem->getReg(insn->getRs1());
    uint32_t val  = mem->loadWord(addr);
    mem->setReg(insn->getRd(), val);

    uint32_t temp = mem->getReg(insn->getRs2());
    mem->setReg(insn->getRs2(), val);
    val = temp;

    mem->storeWord(addr, val);
    mem->updatePc();
}

void Func::SLTIU(Memory* mem, Instruction* insn)
{
    if(mem->getReg(insn->getRs1()) < insn->getImm())
    {
        mem->setReg(insn->getRd(), 1);
    }
    else
    {
        mem->setReg(insn->getRd(), 0);
    }
    mem->updatePc();
}

void Func::SRAI(Memory* mem, Instruction* insn)
{
    uint32_t res = (int)(mem->getReg(insn->getRs1())) >> insn->getImm();
    mem->setReg(insn->getRd(), res);
    mem->updatePc();

    mem->updatePc();
}

void Func::LRW(Memory* mem, Instruction* insn)
{
    //Memory reservation is not supported
    uint32_t addr = mem->getReg(insn->getRs1());
    mem->setReg(insn->getRd(), mem->loadWord(addr));

    mem->updatePc();
}