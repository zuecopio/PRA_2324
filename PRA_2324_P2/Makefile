DyV: DyV.h
	g++ -o test_DyV test_DyV.cpp DyV.h

monedas:
	g++ -o monedas monedas.cpp

mochila:	
	g++ -o mochila mochila.cpp

testDyV: DyV
	./test_DyV

testCambio: monedas
	./monedas
	
testMochila: mochila
	./mochila
	
clean: 
	rm -f test_DyV monedas mochila
