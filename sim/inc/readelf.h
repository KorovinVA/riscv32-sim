#ifndef READELF_H
#define READELF_H

#include <cassert>
#include <vector>
#include <elfio/elfio.hpp>

class ElfReader
{
public:
    struct SectionInfo
    {
        ELFIO::Elf64_Addr addr = 0;
        ELFIO::Elf_Xword  size = 0;
        std::string name;
    };

    ElfReader(const std::string& filename);
    uint64_t getImageSize() const;
    uint64_t getEntryPoint() const;
    void load(uint8_t* mem);
    ~ElfReader();

    std::vector<SectionInfo> execSections;
private:
    ELFIO::elfio elfio;
    const std::string& elfFileName;
};

#endif //READELF_H