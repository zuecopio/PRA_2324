all: main

BrazoRobotico.o: BrazoRobotico.cpp BrazoRobotico.h
	g++ -c BrazoRobotico.cpp

main: BrazoRobotico.o
	g++ -o main main.cpp BrazoRobotico.o

clean: 
	rm -f *.o main

test: all
	./main
