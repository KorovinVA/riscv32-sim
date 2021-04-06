# RISC-V 32I simulator

## Requirements
1. linux
2. llc with LLVM version 10.0.1 or higher
3. cmake version 3.10
4. ruby version 2.7
5. g++ version 9.3

## Installation
Cloning 
```bash
> git clone --recursive https://github.com/KorovinVA/riscv32-sim.git
> git clone https://github.com/google/googletest.git riscv32-sim/benchmark/googletest
```
Building
```bash
> cd riscv32-sim
> ruby build.rb
```

## Usage
After installation you must set RISCV32I_SIM enviroment variable.\
It must something like RISCV32I_SIM=\somepath\riscv32-sim.

Then you can execute a test. For example:
```bash
> ./build/riscv tests/8_queens/8_queens.out
```

## Contributing
Pull requests are welcome.