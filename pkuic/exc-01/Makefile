p01.o: p01.cpp
	g++ -c -Wall -o p01.o p01.cpp
p01: p01.o
	g++ -o p01 p01.o
p02: p02.cpp
	g++ -o p02 p02.cpp

all: p01 p02

clean:
	-rm *.o p01 p02
