all: hello

hello: main.o readelf.o memory.o kernel.o instruction.o
	g++ main.o readelf.o memory.o kernel.o instruction.o -lelf -o riscv32-sim

main.o: main.cpp
	g++ -c main.cpp

readelf.o: readelf.cpp
	g++ -c readelf.cpp

memory.o: memory.cpp
	g++ -c memory.cpp

kernel.o: kernel.cpp
	g++ -c kernel.cpp

instruction.o: instruction.cpp
	g++ -c instruction.cpp

clean:
	rm -rf *.o riscv32-sim