/*-----------------------------------------------------+
 |     T E S T _ D Y V . H                             |
 +-----------------------------------------------------+
 |     Versión     : test_DyV_v1                       | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Test para probar las funciones    |
 |                   genéricas DyV                     |
 +-----------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <chrono>
#include "DyV.h"

#define  SIZE 7
#define   INT 0
#define FLOAT 1
#define  CHAR 2

using namespace std;

vector<int>   a(SIZE);
vector<float> b(SIZE);
vector<char>  c(SIZE);

int X_int;
float X_float;
char X_char;


int main (void)
{
	char tipo;
	int exit = false;
	double tiempo[3];
	
	while(!exit)
	{
		system("clear");
	
		cout << "/*-----------------------------------------------------+ " << endl;
 		cout << " |     T E S T _ D Y V . H                             | " << endl;
		cout << " +-----------------------------------------------------+ " << endl;
		cout << " |     Versión     : P02_v1                            | " << endl;
		cout << " |     Autor       : Marcos Belda Martínez             | " << endl;
		cout << " |     Asignatura  : PRA-GIIROB                        | " << endl;
		cout << " |                                                     | " << endl;
		cout << " |     Descripción :                                   | " << endl;
		cout << " |        Test para probar las funciones genéricas DyV | " << endl;
		cout << " |                                                     | " << endl;
		cout << " |        a) - TEST BUSQUEDA BINARIA                   | " << endl;
		cout << " |        b) - TEST BUSQUEDA BINARIA INV               | " << endl;
		cout << " |        c) - TEST QUICK SORT (pivote = INI)          | " << endl;
		cout << " |        d) - TEST QUICK SORT (pivote = FIN)          | " << endl;
		cout << " |        e) - TEST QUICK SORT (pivote = MID)          | " << endl;
		cout << " |        f) - TEST QUICK SORT (pivote = RANDOM)       | " << endl;
		cout << " |        g) - TIEMPOS DE EJECUCIÓN QUICK SORT         | " << endl;
		cout << " |        h) - EXIT                                    | " << endl;
		cout << " +-----------------------------------------------------*/" << endl;
		
		cout << endl << " --> OPCIPCIÓN: "; 
		cin >> tipo;
	
		system("clear");
		
		switch(tipo)
		{
		
			//-----[ TEST BUSQUEDA BINARIA ]---------------------------(+)
			
			case 'a':
				cout << " *********************************" << endl;
				cout << " ***   TEST BUSQUEDA BINARIA   ***" << endl;
				cout << " *********************************" << endl;
				cout << endl;
		
				RellenarAscendente(a, INT); cout << " A = "; print(a);
				do {
					cout << "   Introduce un INT para buscarlo en el vector: ";
					cin >> X_int;
				} while (BusquedaBinaria(X_int, a, 0, a.size()-1) == -1);
		
				cout << endl;
		
				RellenarAscendente(b, FLOAT); cout << " B = "; print(b);
				do {
					cout << "   Introduce un FLOAT para buscarlo en el vector: ";
					cin >> X_float;
				} while (BusquedaBinaria(X_float, b, 0, b.size()-1) == -1);
		
				cout << endl;
		
				RellenarAscendente(c, CHAR); cout << " C = "; print(c);
				do {
					cout << "   Introduce un CHAR para buscarlo en el vector: ";
					cin >> X_char;
				} while (BusquedaBinaria(X_char, c, 0, c.size()-1) == -1);
				
				cout << endl << " Presiona enter para continuar... ";
				getchar();
				getchar();
				
				break;
				
			//---------------------------------------------------------(-)
				
				
			//-----[ TEST BUSQUEDA BINARIA INV ]-----------------------(+)
			
			case 'b':
				cout << " *********************************" << endl;
				cout << " *** TEST BUSQUEDA BINARIA INV ***" << endl;
				cout << " *********************************" << endl;
				
				cout << endl;
				
				RellenarDescendente(a, INT); cout << " A = "; print(a);
				do {
					cout << "   Introduce un INT para buscarlo en el vector: ";
					cin >> X_int;
				} while (BusquedaBinaria_INV(X_int, a, 0, a.size()-1) == -1);
	
				cout << endl;
				
				RellenarDescendente(b, FLOAT); cout << " B = "; print(b);
				do {
					cout << "   Introduce un FLOAT para buscarlo en el vector: ";
					cin >> X_float;
				} while (BusquedaBinaria_INV(X_float, b, 0, b.size()-1) == -1);
				
				cout << endl;
				
				RellenarDescendente(c, CHAR); cout << " C = "; print(c);
				do {
					cout << "   Introduce un CHAR para buscarlo en el vector: ";
					cin >> X_char;
				} while (BusquedaBinaria_INV(X_char, c, 0, c.size()-1) == -1);
				
				cout << endl << " Presiona enter para continuar... ";
				getchar();
				getchar();
				
				break;
				
			//---------------------------------------------------------(-)
	
	
			//-----[ TEST QUICK SORT (pivote = INI) ]------------------(+)
			
			case 'c':
				cout << " **************************************" << endl;
				cout << " *** TEST QUICK SORT (pivote = INI) ***" << endl;
				cout << " **************************************" << endl;
				
				cout << endl;
				
				cout << "   Vector ANTES de ordenar ----> A = ";
				RellenarRandom(a, INT); print(a);
				QuickSort_INI(a, 0, a.size()-1);
				cout << "   Vector DESPUÉS de ordenar --> A = ";
				print(a);
				
				cout << endl;
				
				cout << "   Vector ANTES de ordenar ----> B = ";
				RellenarRandom(b, FLOAT); print(b);
				QuickSort_INI(b, 0, b.size()-1);
				cout << "   Vector DESPUÉS de ordenar --> B = ";
				print(b);
		
				cout << endl;
				
				cout << "   Vector ANTES de ordenar ----> C = ";
				RellenarRandom(c, CHAR); print(c);
				QuickSort_INI(c, 0, c.size()-1);
				cout << "   Vector DESPUÉS de ordenar --> C = ";
				print(c);
				
				cout << endl << " Presiona enter para continuar... ";
				getchar();
				getchar();
				
				break;
				
			//---------------------------------------------------------(-)
		
		
			//-----[ TEST QUICK SORT (pivote = FIN) ]------------------(+)
			
			case 'd':
				cout << " **************************************" << endl;
				cout << " *** TEST QUICK SORT (pivote = FIN) ***" << endl;
				cout << " **************************************" << endl;
		
				cout << endl;
				
				cout << "   Vector ANTES de ordenar ----> A = ";
				RellenarRandom(a, INT); print(a);
				QuickSort_FIN(a, 0, a.size()-1);
				cout << "   Vector DESPUÉS de ordenar --> A = ";
				print(a);
				
				cout << endl;
				
				cout << "   Vector ANTES de ordenar ----> B = ";
				RellenarRandom(b, FLOAT); print(b);
				QuickSort_FIN(b, 0, b.size()-1);
				cout << "   Vector DESPUÉS de ordenar --> B = ";
				print(b);
		
				cout << endl;
				
				cout << "   Vector ANTES de ordenar ----> C = ";
				RellenarRandom(c, CHAR); print(c);
				QuickSort_FIN(c, 0, c.size()-1);
				cout << "   Vector DESPUÉS de ordenar --> C = ";
				print(c);
							
				cout << endl << " Presiona enter para continuar... ";
				getchar();
				getchar();
				
				break;
			
			//---------------------------------------------------------(-)
			
					
			//-----[ TEST QUICK SORT (pivote = MID) ]------------------(+)
			
			case 'e':
				cout << " **************************************" << endl;
				cout << " *** TEST QUICK SORT (pivote = MID) ***" << endl;
				cout << " **************************************" << endl;
		
				cout << endl;
				
				cout << "   Vector ANTES de ordenar ----> A = ";
				RellenarRandom(a, INT); print(a);
				QuickSort_MID(a, 0, a.size()-1);
				cout << "   Vector DESPUÉS de ordenar --> A = ";
				print(a);
				
				cout << endl;
				
				cout << "   Vector ANTES de ordenar ----> B = ";
				RellenarRandom(b, FLOAT); print(b);
				QuickSort_MID(b, 0, b.size()-1);
				cout << "   Vector DESPUÉS de ordenar --> B = ";
				print(b);
		
				cout << endl;
				
				cout << "   Vector ANTES de ordenar ----> C = ";
				RellenarRandom(c, CHAR); print(c);
				QuickSort_MID(c, 0, c.size()-1);
				cout << "   Vector DESPUÉS de ordenar --> C = ";
				print(c);
							
				cout << endl << " Presiona enter para continuar... ";
				getchar();
				getchar();
				
				break;
			
			//---------------------------------------------------------(-)
			
					
			//-----[ TEST QUICK SORT (pivote = RANDOM) ]---------------(+)
			
			case 'f':
				cout << " *****************************************" << endl;
				cout << " *** TEST QUICK SORT (pivote = RANDOM) ***" << endl;
				cout << " *****************************************" << endl;
		
				cout << endl;
				
				cout << "   Vector ANTES de ordenar ----> A = ";
				RellenarRandom(a, INT); print(a);
				QuickSort_RANDOM(a, 0, a.size()-1);
				cout << "   Vector DESPUÉS de ordenar --> A = ";
				print(a);
				
				cout << endl;
				
				cout << "   Vector ANTES de ordenar ----> B = ";
				RellenarRandom(b, FLOAT); print(b);
				QuickSort_MID(b, 0, b.size()-1);
				cout << "   Vector DESPUÉS de ordenar --> B = ";
				print(b);
		
				cout << endl;
				
				cout << "   Vector ANTES de ordenar ----> C = ";
				RellenarRandom(c, CHAR); print(c);
				QuickSort_MID(c, 0, c.size()-1);
				cout << "   Vector DESPUÉS de ordenar --> C = ";
				print(c);
							
				cout << endl << " Presiona enter para continuar... ";
				getchar();
				getchar();
				
				break;
				
			//---------------------------------------------------------(-)
			
			
			//-----[ TIEMPOS DE EJECUCIÓN QUICK SORT ]-----------------(+)
			
			case 'g':
				cout << " ***************************************" << endl;
				cout << " *** TIEMPOS DE EJECUCIÓN QUICK SORT ***" << endl;
				cout << " ***************************************" << endl;
		
				cout << endl;
				
				
				//+++++[ QUICK SORT (pivote = INI) ]+++++++++++++++(+)
							
				for(int i = 0; i < 4; i++) {
				
				tiempo[INT] = 0.0;
				tiempo[FLOAT] = 0.0;
				tiempo[CHAR] = 0.0;
				
				for(int j = 0; j < 100000; j++)
				{
					RellenarRandom(a, INT);
					auto start = chrono::system_clock::now();
										
					switch(i) {
						case 0:
							QuickSort_INI(a, 0, a.size()-1);
							break;
						case 1:
							QuickSort_FIN(a, 0, a.size()-1);
							break;
						case 2:
							QuickSort_MID(a, 0, a.size()-1);
							break;
						case 3:
							QuickSort_RANDOM(a, 0, a.size()-1);
							break;
					}
					
					auto end = std::chrono::system_clock::now();
					chrono::duration<float, micro> duration = end - start;
					tiempo[INT] = tiempo[INT] + duration.count();
					
					RellenarRandom(b, FLOAT);
					start = chrono::system_clock::now();
										
					switch(i) {
						case 0:
							QuickSort_INI(b, 0, b.size()-1);
							break;
						case 1:
							QuickSort_FIN(b, 0, b.size()-1);
							break;
						case 2:
							QuickSort_MID(b, 0, b.size()-1);
							break;
						case 3:
							QuickSort_RANDOM(b, 0, b.size()-1);
							break;
					}
					
					end = std::chrono::system_clock::now();
					duration = end - start;
					tiempo[FLOAT] = tiempo[FLOAT] + duration.count();
										
					RellenarRandom(c, CHAR);
					start = chrono::system_clock::now();
										
					switch(i) {
						case 0:
							QuickSort_INI(c, 0, c.size()-1);
							break;
						case 1:
							QuickSort_FIN(c, 0, c.size()-1);
							break;
						case 2:
							QuickSort_MID(c, 0, c.size()-1);
							break;
						case 3:
							QuickSort_RANDOM(c, 0, c.size()-1);
							break;
					}
					
					end = std::chrono::system_clock::now();
					duration = end - start;
					tiempo[CHAR] = tiempo[CHAR] + duration.count();
					
				}
				
				string tipo;
				
				switch(i) {
					case 0:
						tipo = "INI";
						break;
					case 1:
						tipo = "FIN";
						break;
					case 2:
						tipo = "MID";
						break;
					case 3:
						tipo = "RANDOM";
						break;
				}
				
				cout << " T. medio QuickSort_" << tipo << " en array de INT: ";
				cout << "\t" << setprecision(2) << (tiempo[INT]) / 100000  << "\t" << " us" << endl;
				
				cout << " T. medio QuickSort_" << tipo << " en array de FLOAT: ";
				cout << "\t" << setprecision(2) << (tiempo[FLOAT]) / 100000  << "\t" << " us" << endl;
				
				cout << " T. medio QuickSort_" << tipo << " en array de CHAR: ";
				cout << "\t" << setprecision(2) << (tiempo[CHAR]) / 100000  << "\t" << " us" << endl;
								
				cout << " --> Promedio " << tipo << ": " << ( (tiempo[INT] + tiempo[FLOAT] + tiempo[CHAR]) / 3 ) / 100000.0 << " us" << endl;
				
				cout << endl;
				
				}
				
				//+++++++++++++++++++++++++++++++++++++++++++++++++(+)
								
				cout << " Presiona enter para continuar... ";
				getchar();
				getchar();
				
				break;
			
			//---------------------------------------------------------(-)
			
			default:
				cout << " Exit... " << endl;
				exit = true;
				break;	
		}
	}
	return 0;
}
