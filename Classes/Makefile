all: sample

sample: assignment.o itemlist.o itemnode.o fruitnode.o vegnode.o 
	    g++ assignment.o itemlist.o itemnode.o fruitnode.o vegnode.o -o sample

assignment.o: assignment.cpp
	g++ -c assignment.cpp
itemlist.o: itemlist.cpp
	g++ -c itemlist.cpp

itemnode.o: itemnode.cpp
	g++ -c itemnode.cpp

fruitnode.o: fruitnode.cpp
	g++ -c fruitnode.cpp

vegnode.o: vegnode.cpp
	g++ -c vegnode.cpp

clean:
	rm *o sample
