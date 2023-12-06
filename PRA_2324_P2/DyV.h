/*-----------------------------------------------------+
 |     D Y V . H                                       |
 +-----------------------------------------------------+
 |     Versión     : DyV_v1                            | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Definición e implemantación de    |
 |                   funciones genéricas DyV           |
 +-----------------------------------------------------*/

#ifndef DYV_H
#define DYV_H

#include <iostream>
#include <vector>

using namespace std;


/****************************************************************/
/*                      RellenarAscendente                      */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Función encargada de rellenar de forma ascendente un vector. */
/*                                                              */
/* ENTRADA: vector<T> &V.                                       */
/*                                                              */
/* SALIDA: void.                                                */
/****************************************************************/

template <typename T>
void RellenarAscendente(vector<T>& V, int tipo)
{
	switch(tipo)
	{
		case 0:
			for (int i = 0; i < V.size(); i++) { V[i] = i + 1; }
			break;
		case 1:
			for (int i = 0; i < V.size(); i++) { V[i] = 1.1 * (i + 1); } 
			break;
		case 2:
			for (int i = 0; i < V.size(); i++) { V[i] = 'a' + (0x01 * i); } 
			break;
	}	
}

/****************************************************************/
/*                     RellenarDescendente                      */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Función encargada de rellenar de forma ascendente un vector. */
/*                                                              */
/* ENTRADA: vector<T> &V.                                       */
/*                                                              */
/* SALIDA: void.                                                */
/****************************************************************/

template <typename T>
void RellenarDescendente(vector<T>& V, int tipo)
{
	switch(tipo)
	{
		case 0:
			for (int i = V.size()-1; i >= 0; i--) { V[i] = ((V.size()-1) - i) + 1; }
			break;
		case 1:
			for (int i = V.size()-1; i >= 0; i--) { V[i] = 1.1 * (((V.size()-1) - i) + 1); } 
			break;
		case 2:
			for (int i = V.size()-1; i >= 0; i--) { V[i] = 'a' + (0x01 * ((V.size()-1) - i)); } 
			break;
	}	
}

/****************************************************************/
/*                        RellenarRandom                        */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Función encargada de rellenar de forma ascendente un vector. */
/*                                                              */
/* ENTRADA: vector<T> &V.                                       */
/*                                                              */
/* SALIDA: void.                                                */
/****************************************************************/

template <typename T>
void RellenarRandom(vector<T>& V, int tipo)
{
	srand(time(NULL));
	switch(tipo)
	{
		case 0:
			for (int i = 0; i < V.size(); i++) { V[i] = rand() % 10; }
			break;
		case 1:
			for (int i = 0; i < V.size(); i++) { V[i] = (rand() % 10) + (0.1 * (rand() % 10)); } 
			break;
		case 2:
			for (int i = 0; i < V.size(); i++) { V[i] = 'a' + (0x01 * (rand() % 26)); } 
			break;
	}	
}

/****************************************************************/
/*                            swap                              */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Función encargada de intercambiar dos elementos de un vector.*/
/*                                                              */
/* ENTRADA: vector<T> &V, int i, int j.                         */
/*                                                              */
/* SALIDA: void.                                                */
/****************************************************************/

template <typename T>
void swap(vector<T>& V, int i, int j)
{
	T aux = V[i];
	V[i] = V[j];
	V[j] = aux;
}

/****************************************************************/
/*                           print                              */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Función encargada de imprimir el vector genérco.             */
/*                                                              */
/* ENTRADA: vector<T> &V.                                       */
/*                                                              */
/* SALIDA: void.                                                */
/****************************************************************/

template <typename T>
void print(vector<T>& V)
{
	cout << "{";
	for(int i = 0; i < V.size(); i++)
	{
		(i == V.size()-1) ? (cout << V[i]) : (cout << V[i] << ", ");
	}
	cout << "}" << endl;
}

/****************************************************************/
/*                      BusquedaBinaria                         */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Busca el elemento genérico X en un vector ordenado de forma  */
/* ascendente.                                                  */
/*                                                              */
/* ENTRADA: T X, vector<T> &V, int ini, int fin.                */
/*                                                              */
/* SALIDA: Si X está en el vector, devuelve la posición del     */
/*         elemento en el vector. Si no está, devuelve -1.      */ 
/****************************************************************/

template <typename T>
T BusquedaBinaria(T X, vector<T>& V, int ini, int fin)
{
	while(ini <= fin)
	{
		int medio = (ini + fin) / 2; 
       		if (V[medio] == X)
       		{
       			cout << "  -> El elemento [" << X << "] se encuentra en la posición " << medio;
       			cout << endl;
       			return medio;
       		}
		else if(V[medio] > X) { return BusquedaBinaria(X, V, ini, medio - 1); }
		else { return BusquedaBinaria(X, V, medio + 1, fin); }
	}

	/* Si X no está en V, entonces devuelve -1 */
	cout << "  -> El elemento [" << X << "] no se encuentra en el vector" << endl;
	return -1;
}

/****************************************************************/
/*                   BusquedaBinaria_INV                        */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Busca el elemento genérico X en un vector ordenado de forma  */
/* descendente.                                                 */
/*                                                              */
/* ENTRADA: T X, vector<T> &V, int ini, int fin.                */
/*                                                              */
/* SALIDA: Si X está en el vector, devuelve la posición del     */
/*         elemento en el vector. Si no está, devuelve -1.      */ 
/****************************************************************/

template <typename T>
T BusquedaBinaria_INV(T X, vector<T>& V, int ini, int fin)
{
        while(ini <= fin) 
        {       
                int medio = (ini + fin) / 2;
                if (V[medio] == X)
                {
       			cout << "  -> El elemento [" << X << "] se encuentra en la posición " << medio;
       			cout << endl;
       			return medio;
       		}
                else if(V[medio] > X) { return BusquedaBinaria_INV(X, V, medio + 1, fin); }
                else { return BusquedaBinaria_INV(X, V, ini, medio - 1); }
        }

	/* Si X no está en V, entonces devuelve -1 */
	cout << "  -> El elemento [" << X << "] no se encuentra en el vector" << endl;
	return -1;
}

/****************************************************************/
/*                          Partition                           */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Función de QuickSort adaptaativa para cada caso, cuando el   */
/* pivote es INI, FIN, MID o RANDOM.                            */
/*                                                              */
/* ENTRADA: vector<T> &V, int ini, int fin, pivote_pos          */
/*                                                              */
/* SALIDA: nueva pivote_pos                                     */ 
/****************************************************************/

template <typename T>         
int Partition(vector<T>& V, int ini, int fin, int pivote_pos)
{
	T pivote = V[pivote_pos];
	int result;
	int i = ini-1;
	int j = fin+1;
	
	do {
		do { if(i != fin) { i = i+1; }
		} while( (V[i] < pivote || i == pivote_pos) && i < fin );
		
		do { if(j != ini) { j = j-1; }
		} while( (V[j] > pivote || j == pivote_pos) && j > ini );
		
		swap(V, i, j);
		
	} while(i < j);
        
	swap(V, i, j);
	
	// Cuando el pivote es INI
	if(j >= pivote_pos)
	{
		swap(V, pivote_pos, j);
		result = j;
	}
	
	// Cuando el pivote es FIN
	else if(i <= pivote_pos)
	{
		swap(V, pivote_pos, i);
		result = i;
	}
	
	// Cuando el pivote es MID o RANDOM (no es ni INI ni FIN)
	else { result = pivote_pos; }
	
	return result;
}

/****************************************************************/
/*                        QuickSort_INI                         */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Emplea el primer elemento V[0] como pivote. Mueve los        */
/* elementos < V[0] hacia la cabeza, pos = 0 y los elementos >  */
/* V[0] hacia la cola, pos = size-1.                            */
/*                                                              */
/* ENTRADA: vector<T> &V, int ini, int fin.                     */
/*                                                              */
/* SALIDA: void.                                                */ 
/****************************************************************/

template <typename T>
void QuickSort_INI(vector<T>& V, int ini, int fin)
{
	if(ini < fin)
	{
		int pivote = Partition(V, ini, fin, ini);
		QuickSort_INI(V, ini, pivote-1);
		QuickSort_INI(V, pivote+1, fin);
	}
}

/****************************************************************/
/*                        QuickSort_FIN                         */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Emplea el último elemento V[size-1] como pivote. Mueve los   */
/* elementos < V[size-1] hacia la cabeza, pos = 0 y los         */
/* elementos > V[size-1] hacia la cola, pos = size-1.           */
/*                                                              */
/* ENTRADA: vector<T> &V, int ini, int fin.                     */
/*                                                              */
/* SALIDA: void.                                                */ 
/****************************************************************/

template <typename T>
void QuickSort_FIN(vector<T>& V, int ini, int fin)
{
	if(ini < fin)
	{
		int pivote = Partition(V, ini, fin, fin);
		QuickSort_FIN(V, ini, pivote-1);
		QuickSort_FIN(V, pivote+1, fin);
	}
}

/****************************************************************/
/*                        QuickSort_MID                         */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Emplea el elemento del medio V[medio] como pivote. Mueve los */
/* elementos < V[medio] hacia la cabeza, pos = 0 y los          */
/* elementos > V[medio] hacia la cola, pos = size-1.            */
/*                                                              */
/* ENTRADA: vector<T> &V, int ini, int fin.                     */
/*                                                              */
/* SALIDA: void.                                                */ 
/****************************************************************/

template <typename T>
void QuickSort_MID(vector<T>& V, int ini, int fin)
{
	if(ini < fin)
	{
		int medio = (ini + fin) / 2;
		int pivote = Partition(V, ini, fin, medio);
		QuickSort_MID(V, ini, pivote-1);
		QuickSort_MID(V, pivote+1, fin);
	}
}

/****************************************************************/
/*                       QuickSort_RANDOM                       */
/*--------------------------------------------------------------*/
/*                                                              */
/* DESCRIPCION:                                                 */
/* Emplea el elemento del medio V[random] como pivote. Mueve los*/
/* elementos < V[random] hacia la cabeza, pos = 0 y los         */
/* elementos > V[random] hacia la cola, pos = size-1.           */
/*                                                              */
/* ENTRADA: vector<T> &V, int ini, int fin.                     */
/*                                                              */
/* SALIDA: void.                                                */ 
/****************************************************************/

template <typename T>
void QuickSort_RANDOM(vector<T>& V, int ini, int fin)
{
	srand(time(NULL));
	if(ini < fin)
	{
		int random = rand() % (ini + fin+1);
		int pivote = Partition(V, ini, fin, random);
		QuickSort_MID(V, ini, pivote-1);
		QuickSort_MID(V, pivote+1, fin);
	}
}

#endif 
