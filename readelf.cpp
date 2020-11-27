#include "readelf.h"

ElfReader::ElfReader(const char* elf) :
    phdrs(),
    data()
{
    if (elf_version(EV_CURRENT ) == EV_NONE)
    {
        throw std::string("ELF library version problem");
    }

    OpenElf(elf);
    ReadHeader();
    LoadPHdrs();
    LoadData();
}


void ElfReader::OpenElf(const char* elf)
{
    elfFd = open(elf, O_RDONLY, 0);
    if(elfFd < 0)
    {
        throw std::string(std::strerror(errno));
    }
    elfData = elf_begin(elfFd, ELF_C_READ, NULL);
}

void ElfReader::ReadHeader()
{
    if(gelf_getehdr(elfData, &ehdr) == NULL) 
    {
        throw std::string(elf_errmsg(-1));
    }
    entry = ehdr.e_entry;
}

void ElfReader::LoadPHdrs()
{
    size_t phNum = 0;
    if(elf_getphdrnum(elfData, &phNum) != 0)
    {
        throw std::string(elf_errmsg(-1));
    }

    GElf_Phdr phdr;
    for (size_t i = 0; i < phNum; ++i) 
    {
        if (gelf_getphdr(elfData, i, &phdr) != &phdr)
        {
            throw std::string(elf_errmsg(-1));
        }
        phdrs.push_back(phdr);
    }
}

void ElfReader::LoadData()
{
    auto maxSegment = *std::max_element(phdrs.begin(), phdrs.end(), 
                                        [](GElf_Phdr a, GElf_Phdr b)
                                            { return a.p_vaddr + a.p_memsz < b.p_vaddr + b.p_memsz; }
                                        );
    size_t maxVecSize = maxSegment.p_vaddr + maxSegment.p_memsz;
    data.resize(maxVecSize);

    for (int i = 0; i < phdrs.size(); ++i)
    {
        void* segment = calloc(1, phdrs[i].p_memsz);

        lseek(elfFd, phdrs[i].p_offset, SEEK_SET);
        if(read(elfFd, segment, phdrs[i].p_memsz) < 0)
        {
            throw std::string(std::strerror(errno));
        }

        for(int j = 0; j < phdrs[i].p_memsz; ++j)
        {
            data[phdrs[i].p_paddr + j] = *((uint8_t*)segment + j);
        }
        free(segment);
    }
}

std::vector<uint8_t>* ElfReader::getRawData()
{
    return &data;
}

uint32_t ElfReader::getEntry()
{
    return entry;
}

ElfReader::~ElfReader()
{
    elf_end(elfData);
    close(elfFd);
}
