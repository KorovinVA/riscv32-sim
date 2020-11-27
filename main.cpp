#include <iostream>
#include <stdlib.h>

#include "readelf.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "USAGE: " << argv[0] << " path-to-elf" << std::endl;
        exit(1);
    }

    try
    {
        ReadElf Elf(argv[1]);
    }
    catch(const std::string &str)
    {
        std::cerr << str << std::endl;
        exit(1);
    }
    return 0;
}