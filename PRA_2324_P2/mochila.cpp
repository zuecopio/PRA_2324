/*-----------------------------------------------------+
 |     M O C H I L A . C P P                           |
 +-----------------------------------------------------+
 |     Versión     : mochila_v1                        | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Definición e implementación del   |
 |                   problema de la mochila con PD.    |
 +-----------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

	vector<int> p {9, 6, 5};
	vector<int> b {38, 40, 24};
	int M = 15;
	int N = p.size();
	vector<vector<int>> T (N + 1, vector<int>(M + 1, -1));
	vector<int> solu(N,0);


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
/* Función que muestra el número de objetos necesarios de cada  */
/* tipo para maximizar el beneficio total del contenido de la   */
/* mochila.                                                     */
/*                                                              */
/* ENTRADA: vector<int> &S, vector<int> &p, vector<int> &b.     */
/*                                                              */
/* SALIDA: void.                                                */
/****************************************************************/

void printSol(vector<int> &S, vector<int> &p, vector<int> &b)
{
	int N = S.size();
	
	cout << "PESO:  " << "BENEFICIO:  " << "UNIDADES:" << endl;
	for(int i = 0; i < N; i++) {
		cout << setw(4) << p[i] << setw(12) << b[i] << setw(11) << S[i] << endl;
	}
	cout << endl;
}

/****************************************************************/
/*                           mochila                            */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Consiste en un conjunto de N elementos con pesos p y valor o */
/* beneficio b, y una mochila que puede transportar un peso     */
/* máximo M. Se debe encontrar qué selección de elementos x     */
/* maximiza el beneficio sin sobrepasar el peso máximo M, es    */
/* decir, el conjunto de elementos que caben en la mochila de   */
/* manera que reporten el máximo beneficio.                     */
/*                                                              */
/* ENTRADA: int i, int j.                                       */
/*                                                              */
/* SALIDA: vector<int>.                                         */
/****************************************************************/

int mochila(int i, int j)
{
	/*-----------------------------------------------------+
	 |  VARIABLES GLOBALES:                                |
	 |      p = vector con los pesos de cada elemento      | 
	 |      b = vector con los beneficios de cada elemento |
	 |      T = tabla de memoria                           |     
	 |      M = peso máximo de la mochila                  |
	 |                                                     |
	 |  VARIABLES DE LA FUNCIÓN:                           |
	 |      i = elemnto que se quiere meter                | 
	 |      j = peso que se puede poner en la mochila      |
	 +-----------------------------------------------------*/
	
	int result;
	
	//-----[ CÁLCULO RESTO DE LA TABLA ]-------------(+)
	if(T[i][j] < 0)
	{
		if(j < p[i-1]) {
			T[i][j] = mochila(i - 1, j);
		}
		
		else {
			T[i][j] = max(mochila(i - 1, j), b[i-1] + mochila(i - 1, j - p[i-1]));
		}
	}
	result = T[i][j];
	//-----------------------------------------------(-)


	//-----[ RECUPERAR SOLUCIÓN ]--------------------(+)
	if(i == N && j == M) {
	
		while(i > 0 && j > 0) {
			if(T[i][j] > T[i-1][j]) {
				solu[i-1] = solu[i-1] + 1;
				j = j - p[i-1];
			}
			else {
				i--;
			}
		}
	}
	return result;
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
	//-----[ INICIALIZAR MATRIZ ]--------------------(+)
	for(int i = 0; i < (N + 1); i++) { T[i][0] = 0; }
	for(int j = 1; j < (M + 1); j++) { T[0][j] = 0; }
	//-----------------------------------------------(-)
	
	int sol = mochila(p.size(), M);
	printSol(solu, p, b);
	cout << "BENEFICIO TOTAL: " << sol << endl;
	
	return 0;
}
