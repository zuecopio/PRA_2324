#include "BrazoRobotico.h" 

using namespace std;

BrazoRobotico::BrazoRobotico(){
	x = 0;
	y = 0;
	z = 0;
}

int BrazoRobotico::getX() { return x; }

int BrazoRobotico::getY() { return y; }

int BrazoRobotico::getZ() { return z; }

int BrazoRobotico::getHolding() { return holding; }

void BrazoRobotico::coger() { holding = 1; }
		
void BrazoRobotico::soltar() { holding = 0; }

void BrazoRobotico::mover( double x, double y, double z ) {
	this->x += x;
	this->y += y;
	this->z += z;
}
