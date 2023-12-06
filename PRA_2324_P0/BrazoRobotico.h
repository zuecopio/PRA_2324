#ifndef BRAZOROBOTICO_H
#define BRAZOROBOTICO_H

#include <iostream>

using namespace std;

class BrazoRobotico {

	private:
		double x;    // coordenada en x
		double y;    // coordenada en y
		double z;    // coordenada en z
		int holding; // sujeta un objeto? sí = 1, no = 0

	public:
		BrazoRobotico();

		int getX();

		int getY();

		int getZ();

		int getHolding();

		void coger();
		
		void soltar();

		void mover( double x, double y, double z );

};

#endif
