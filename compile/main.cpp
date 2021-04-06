#define BUFF_SIZE !REPLACE_BUFF_SIZE!

#include <fstream>
#include <benchmark/benchmark.h>
#include "main.h"

void test_BM(benchmark::State& state)
{
    char* mem = new char[BUFF_SIZE];
    std::ifstream infile("mem", std::ios::binary | std::ios::in);
    infile.read(mem, BUFF_SIZE);
    infile.close();

    for (auto _: state) 
    {
        entry(mem);
    }

    delete[] mem;
}

BENCHMARK(test_BM);
