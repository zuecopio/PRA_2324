#include "BrazoRobotico.h"

int main() {
	
	cout << "Encendiendo robot... " << endl << endl;
	BrazoRobotico UR;
	cout << "Posición inicial (x,y,z): ";
	cout << "(" << UR.getX() << "," << UR.getY() << "," << UR.getZ() << ")" << endl << endl;

	
	// PUNTO DE PASO 1 (PRE-PICK)
	cout << "Punto de paso 1 (pre-pick): ";
	UR.mover(200,0,100);
	cout << "(" << UR.getX() << "," << UR.getY() << "," << UR.getZ() << ")" << endl;
	cout << "Sujeta objeto? "; UR.getHolding() == 1 ? cout << "sí" : cout << "no"; cout << endl << endl;


	// PUNTO DE PASO 2 (PICK)
	cout << "Punto de paso 2 (pick): ";
	UR.mover(200,0,0);
	cout << "(" << UR.getX() << "," << UR.getY() << "," << UR.getZ() << ")" << endl;
	UR.coger();
	cout << "Sujeta objeto? "; UR.getHolding() == 1 ? cout << "sí" : cout << "no"; cout << endl << endl;

	
	// PUNTO DE PASO 3 (PRE-PLACE)
	cout << "Punto de paso 3 (pre-place): ";
	UR.mover(200,300,100);
	cout << "(" << UR.getX() << "," << UR.getY() << "," << UR.getZ() << ")" << endl;
	cout << "Sujeta objeto? "; UR.getHolding() == 1 ? cout << "sí" : cout << "no"; cout << endl << endl;

	// PUNTO DE PASO 4 (PLACE)
	cout << "Punto de paso 2 (pick): ";
	UR.mover(200,300,0);
	cout << "(" << UR.getX() << "," << UR.getY() << "," << UR.getZ() << ")" << endl;
	UR.soltar();
	cout << "Sujeta objeto? "; UR.getHolding() == 1 ? cout << "sí" : cout << "no"; cout << endl << endl;
	
}
