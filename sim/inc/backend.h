#ifndef BACKEND_H
#define BACKEND_H

#include <iostream>
#include <string>
#include <fstream>

class Backend
{
public:
    Backend(const std::string& projDir,
            const std::string& outputDir);
    void run(uint32_t imageSize);
    ~Backend();
private:
    const std::string proj;
    const std::string bInclude;
    const std::string bLib;
    const std::string compileDir;
    const std::string output;
};

#endif //BACKEND_H

