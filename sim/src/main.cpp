#include <iostream>
#include <cstdlib>
#include <string>

#include "../inc/parser.h"
#include "../inc/converter.h"
#include "../inc/backend.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "USAGE: " << argv[0] << " path-to-elf" << std::endl;
        exit(1);
    }
    
    const char* projDirEnv = std::getenv("RISCV32I_SIM");
    if(projDirEnv == nullptr)
    {
        std::cout << "RISCV32I_SIM is not set!" << std::endl;
        exit(1);
    }
    std::string projDir(projDirEnv);
    std::string outputDir = projDir + "/output";
    try
    {
        Parser parse(argv[1], outputDir);
        std::vector<ISA::Instruction> buf = parse.parse();
        uint8_t* elfData = parse.getElfData();

        Converter conv(outputDir,
                       buf,
                       parse.getElfData(),
                       parse.getImageSize(),
                       parse.getEntryPoint());
        conv.translate();

        Backend back(projDir, outputDir);
        back.run(parse.getImageSize());

        std::cout << "Middle-end was successful! Now you can run: ruby " << outputDir << "/run.rb" << std::endl;
    }
    catch(const std::string &str)
    {
        std::cerr << str << std::endl;
        exit(1);
    }
    return 0;
}
