all: sample

sample: hashTable.o
	g++ hashTable.o -o sample

main.o: hashTable.cpp
	g++ -c hashTable.cpp

clean: 
	rm *o sample