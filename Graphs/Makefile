all: sample

sample: main.o
	g++ main.o -o sample

main.o: main.cpp
	g++ -c main.cpp

clean: 
	rm *o sample