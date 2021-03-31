#include <iostream>
#include <cstdlib>

#include "../inc/parser.h"
#include "../inc/converter.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "USAGE: " << argv[0] << " path-to-elf" << std::endl;
        exit(1);
    }

    try
    {
        Parser parse(argv[1]);
        std::vector<ISA::Instruction> buf = parse.parse();

        Converter conv(buf);
        conv.translate();
    }
    catch(const std::string &str)
    {
        std::cerr << str << std::endl;
        exit(1);
    }
    return 0;
}