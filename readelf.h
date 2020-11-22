#ifndef READELF_H
#define READELF_H

#include <elf.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class ReadElf
{
public:
    ReadElf(const char* elf);
private:
    FILE* m_elf;
};

#endif //READELF_H