/*-----------------------------------------------------+
 |     M O N E D A S . C P P                           |
 +-----------------------------------------------------+
 |     Versión     : monedas_v1                        | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Definición e implementación del   |
 |                   cambio de monedas con PD          |
 +-----------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;


/****************************************************************/
/*                   printTable (no se usa)                     */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Función que imprime el contenido de la tabla con el mínimo de*/
/* monedas para una cantidad concreta.                          */
/*                                                              */
/* ENTRADA: vector<vector<int>> &T, int M.                      */
/*                                                              */
/* SALIDA: void.                                                */
/****************************************************************/

void printTable(vector<vector<int>> &T, int M)
{
	int N = T.size();
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M+1; j++) {
			cout << setw(3) << T[i][j] << " ";
		}
		cout << endl;
	}
}

/****************************************************************/
/*                          printSol                            */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Función que devuelve el número de monedas necesarias de cada */
/* tipo para devolver la cantidad deseada (M) con el mínimo de  */
/* monedas.                                                     */
/*                                                              */
/* ENTRADA: vector<int> &S, vector<int> &V.                     */
/*                                                              */
/* SALIDA: void.                                                */
/****************************************************************/

void printSol(vector<int> &S, vector<int> &V)
{
	int N = S.size();
	
	for(int i = 0; i < N; i++) {
		cout << " {" << V[i] << "} ";
	}
	cout << endl;
	
	for(int i = 0; i < N; i++) {
		cout << "  " << S[i] << "  ";
	}
	cout << endl;
}

/****************************************************************/
/*                            cambio                            */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Tiene como parámetros de entrada un vector de valores de     */
/* monedas (V), el número de monedas (N) tamaño del array V, y  */
/* una cantidad (M) para que devuelva el número mínimo de       */
/* monedas, valor de la solución óptima.                        */
/*                                                              */
/* ENTRADA: vector<int> &V, int M.                              */
/*                                                              */
/* SALIDA: vector<int>.                                         */
/****************************************************************/

vector<int> cambio(vector<int> &V, int M)
{
	//-----[ INICIALIZAR MATRIZ ]--------------------(+)
	int N = V.size();
	vector<vector<int>> T (N, vector<int>(M + 1, -1));
	T[0][0] = 0;
	//-----------------------------------------------(-)
		
	//-----[ CÁLCULO PRIMERA FILA ]------------------(+)
	for(int j = 1; j < M+1; j++) {
		if(j >= V[0] && T[0][j-V[0]] != -1) {
			T[0][j] = 1 + T[0][j-V[0]];
		}
	}
	//-----------------------------------------------(-)
		
	//-----[ CÁLCULO RESTO DE LA TABLA ]-------------(+)
	for(int i = 1; i < N; i++) {
		T[i][0] = 0;
		
		for(int j = 1; j < M+1; j++) {
			if(j < V[i] || T[i][j-V[i]] == -1) {
				T[i][j] = T[i-1][j];
			}
			
			else if(T[i-1][j] != -1) {
				T[i][j] = min(T[i-1][j], 1 + T[i][j-V[i]]);
			}
			
			else {
				T[i][j] = 1 + T[i][j-V[i]];
			}
		}	
	}
	//-----------------------------------------------(-)

	
	//-----[ RECUPERAR SOLUCIÓN ]--------------------(+)
	vector<int> sol(N,0);
	int i = N-1;
	int j = M;
	
	while(i >= 0 && j != 0) {
		if(i == 0 || T[i][j] != T[i-1][j]) {
			sol[i] = sol[i] + 1;
			j = j - V[i];
		}
		
		else {
			i = i - 1;
		}
	}
	return sol;
	//-----------------------------------------------(-)
}

/****************************************************************/
/*                            main                              */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Devolver una cantidad de dinero entera M en el menor número  */
/* de monedas posibles de un conjunto V con diferentes valores  */
/* enteros (se considera que hay un número infinito de esas     */
/* monedas).                                                    */
/*                                                              */
/* ENTRADA: void.                                               */
/*                                                              */
/* SALIDA: int.                                                 */
/****************************************************************/

int main()
{
	srand(time(NULL));

	int M = rand() % 50;
	cout << " --> Devolver M = " << M << "... " << endl << endl;

	vector<int> V{1, 4, 6};
	vector<int> sol = cambio(V, M);
	
	printSol(sol, V);
	
	return 0;
}
