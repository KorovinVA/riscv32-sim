#include "kernel.h"

Kernel::Kernel(Memory* memory, bool tracing):
    trEn(tracing)
{
    mem  = memory;
}

Kernel::~Kernel()
{}