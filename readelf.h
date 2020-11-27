#ifndef READELF_H
#define READELF_H

#include <gelf.h>
#include <fcntl.h>
#include <libelf.h>
#include <unistd.h>
#include <err.h>
#include <stdlib.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cerrno>
#include <cstdint>
#include <vector>
#include <memory> 

class ElfReader
{
public:
    ElfReader(const char* elf);
    ~ElfReader();
    std::vector<uint8_t>* getRawData();
    uint32_t getEntry();
private:
    void OpenElf(const char* elf);
    void ReadHeader();
    void LoadPHdrs();
    void LoadData();

    int       elfFd;
    uint32_t  entry;
    GElf_Ehdr ehdr;
    Elf* elfData = nullptr;
    std::vector<GElf_Phdr> phdrs;
    std::vector<uint8_t>   data;
};

#endif //READELF_H