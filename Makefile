all: hello

hello: main.o readelf.o memory.o kernel.o
	g++ main.o readelf.o memory.o kernel.o -lelf -o riscv32-sim

main.o: main.cpp
	g++ -c main.cpp

readelf.o: readelf.cpp
	g++ -c readelf.cpp

memory.o: memory.cpp
	g++ -c memory.cpp

kernel.o: kernel.cpp
	g++ -c kernel.cpp

clean:
	rm -rf *.o riscv32-sim