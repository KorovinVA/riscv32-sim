#include "readelf.h"

ReadElf::ReadElf(const char* elf)
{
    m_elf = fopen(elf, "rb");
    if(!m_elf)
    {
        perror("Error: ");
        exit(1);
    }

    Elf32_Ehdr header;
    fread(&header, sizeof(header), 1, m_elf);
}