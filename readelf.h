#ifndef READELF_H
#define READELF_H

#include <elf.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cerrno>
#include <cstdint>
#include <vector>
#include <memory> 

class ReadElf
{
    struct Section
    {
        Elf32_Shdr m_shdr;
        void* m_data = nullptr;
        char* name   = nullptr;

        ~Section() 
        { free(m_data); }
    };

public:
    ReadElf(const char* elf);
    ~ReadElf();
private:
    void OpenElf(const char* elf);
    void ReadHeader();
    void SaveSection(int secNum);
    void NameSections();
    void Disassembly();

    FILE*      m_elf = nullptr;
    Elf32_Ehdr m_ehdr;
    const std::string m_err;

    std::vector<std::unique_ptr<Section>> m_sections;
    std::vector<char> m_strtable;
};

#endif //READELF_H