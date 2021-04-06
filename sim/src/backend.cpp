#include "../inc/backend.h"

Backend::Backend(const std::string& projDir, const std::string& outputDir):
    proj(projDir),
    bInclude(proj + "/benchmark/include"),
    bLib(proj + "/benchmark/build/src"),
    compileDir(proj + "/compile"),
    output(outputDir)
{}


void Backend::run(uint32_t imageSize)
{
    // copy and replace main.cpp -> output
    std::ifstream cppIn(compileDir + "/main.cpp");
    std::ofstream cppOut(output    + "/main.cpp");

    std::string line;
    std::string replacement(std::to_string(imageSize));
    std::string toReplace("!REPLACE_BUFF_SIZE!");
    while(std::getline(cppIn, line))
    {
        while(true)
        {
            size_t pos = line.find(toReplace);
            if (pos != std::string::npos)
            {
                line.replace(pos, toReplace.length(), replacement);
            }
            else
           {
                break;
           }
        }
        cppOut << line << "\n";
    }

    // copy main.h -> output
    std::ifstream hIn(compileDir + "/main.h");
    std::ofstream hOut(output    + "/main.h");
    while(std::getline(hIn, line))
    {
        hOut << line << "\n";
    }

    // copy and replace run.rb -> output
    std::ifstream rbIn(compileDir + "/run.rb");
    std::ofstream rbOut(output    + "/run.rb");
    
    std::string benchIncludeReplace("!REPLACE_BENCHMARK_INCLUDE!");
    std::string benchLibReplace("!REPLACE_BENCHMARK_LIB!");
    while(std::getline(rbIn, line))
    {
        while(true)
        {
            size_t pos = line.find(benchIncludeReplace);
            if (pos != std::string::npos)
            {
                std::string benchInclude("\"" + bInclude + "\"");
                line.replace(pos, benchIncludeReplace.length(), benchInclude);
            }
            else
            {
                break;
            }
        }
        while(true)
        {
            size_t pos = line.find(benchLibReplace);
            if (pos != std::string::npos)
            {
                std::string benchLib("\"" + bLib + "\"");
                line.replace(pos, benchLibReplace.length(), benchLib);
            }
            else
            {
                break;
            }
        }
        rbOut << line << "\n";
    }
}

Backend::~Backend() 
{}
