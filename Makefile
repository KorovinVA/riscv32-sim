all: hello

hello: main.o readelf.o memory.o kernel.o instruction.o functions.o
	g++ -O3 main.o readelf.o memory.o kernel.o instruction.o functions.o -lelf -o riscv32-sim

main.o: main.cpp
	g++ -c -O3 main.cpp

readelf.o: readelf.cpp
	g++ -c -O3 readelf.cpp

memory.o: memory.cpp
	g++ -c -O3 memory.cpp

kernel.o: kernel.cpp
	g++ -c -O3 kernel.cpp

instruction.o: instruction.cpp
	g++ -c -O3 instruction.cpp

functions.o: functions.cpp
	g++ -c -O3 functions.cpp

clean:
	rm -rf *.o riscv32-sim