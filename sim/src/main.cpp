#include <iostream>
#include <stdlib.h>

#include "../inc/readelf.h"
#include "../inc/kernel.h"
#include "../inc/memory.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "USAGE: " << argv[0] << " path-to-elf" << std::endl;
        exit(1);
    }

    try
    {
        ElfReader Elf(argv[1]);
        Memory Mem(Elf.getEntry(), Elf.getRawData());
        Kernel Unit(&Mem, false);
        Unit.Run();
    }
    catch(const std::string &str)
    {
        std::cerr << str << std::endl;
        exit(1);
    }
    return 0;
}