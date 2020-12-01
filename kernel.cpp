#include "kernel.h"

Kernel::Kernel(Memory* memory, bool tracing):
    trEn(tracing),
    executed()
{
    mem = memory;

    if(trEn)
    {
        state.open("riscv.state");
        if (!state.is_open())
        {
            throw std::string("Cannot open state file");
        }
    }
}

void Kernel::Run()
{
    for(int i = 0; i < 180000; ++i)
    {
        if(executed.count(mem->getPc()) <= 0)
        {
            //Instruction hasn't been decoded yet
            std::unique_ptr<Instruction> unInsn(new Instruction(mem->PullNextInsn(), mem->getPc()));
            executed.insert(std::pair<uint32_t, std::unique_ptr<Instruction>>(mem->getPc(), std::move(unInsn)));
        }
        Instruction* insn = executed[mem->getPc()].get();

        if(trEn)
        {
            DumpExecInsn(insn);
        }

        insn->process(mem, insn);
        
        if(trEn)
        {
            DumpChangedReg(insn);
        }
    }
}

void Kernel::DumpExecInsn(Instruction* insn)
{
    state << insn->getName() << std::endl;
}

void Kernel::DumpChangedReg(Instruction* insn)
{
    if(insn->getRd() != 0)
    {
        state << std::hex << "\t" << insn->getRName(insn->getRd()) << " = " << "0x" <<
            std::setw(8) << std::setfill('0') << mem->getReg(insn->getRd()) << std::endl;
    }
}

Kernel::~Kernel()
{
    if(trEn)
    {
        state.close();
    }
}