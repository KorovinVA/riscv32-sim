#include "kernel.h"

Kernel::Kernel(Memory* memory, bool tracing):
    trEn(tracing)
{
    mem = memory;

}

void Kernel::Run()
{
    Instruction insn(mem->PullNextInsn());
}

Kernel::~Kernel()
{}