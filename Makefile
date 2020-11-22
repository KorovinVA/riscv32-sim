all: hello

hello: main.o readelf.o
	g++ main.o readelf.o -o riscv32-sim

main.o: main.cpp
	g++ -c main.cpp

readelf.o: readelf.cpp
	g++ -c readelf.cpp

clean:
	rm -rf *.o riscv32-sim