/*-----------------------------------------------------+
 |     H A S H T A B L E . H                           |
 +-----------------------------------------------------+
 |     Versión     : P03_v1                            | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Declaración e implementación de   |
 |                   la clase HashTable                |
 +-----------------------------------------------------*/

#ifndef HASHTABLE_H
#define HASHTABLE_h

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "../PRA_2324_P1/ListLinked.h"

using namespace std;

template <typename V> 
class HashTable : public Dict<V> {
	
	private:
		
		/****************************************************************/
		/*                         n (atributo)                         */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Número de elementos almacenados actualmente en la tabla hash.*/
		/*                                                              */
		/****************************************************************/

		int n;
		
		/****************************************************************/
		/*                        max (atributo)                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Tamaño de la tabla hash (número total de cubetas).           */
		/*                                                              */
		/****************************************************************/

		int max;
				
		/****************************************************************/
		/*                 Tabla de cubetas (atributo)                  */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Tabla de cubetas, representada por un array de punteros a    */
		/* listas enlazadas (tipo ListLinked<T>) que almacena pares     */
		/* key->value (tipo TableEntry<V>).                             */
		/*                                                              */
		/****************************************************************/

		ListLinked<TableEntry<V>>* table;
		
		/****************************************************************/
		/*                       h (función hash)                       */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Función hash que devuelve la posición (cubeta) en la tabla   */
		/* hash de key. Se calculará como el resto de la divisón entre  */
		/* la suma de los valores ASCII numéricos de los caracteres de  */
		/* la clave y el tamaño de la tabla hash.                       */
		/*                                                              */
		/* ENTRADA: string key.                                         */
		/*                                                              */
		/* SALIDA: int (cubeta).                                        */
		/****************************************************************/

		int h (string key)
		{
			int sumASCII = 0;
			
			for (int i = 0; i < key.size(); i++)
			{
				sumASCII += int(key.at(i));
			}
			
			return sumASCII % capacity();
		}
	
	public:
	
		//----// INSERT //--------------------------------------+
		void insert (string key, V value) override
		{
			int pos = h(key);
			TableEntry<V> aux(key, value);
			
			if ((table[pos].search(aux)) == -1) {
				table[pos].insert(table[pos].size(), aux);
				n++;
			}

			else { throw runtime_error("Key '" + key + "' already exists!"); }			
		}
		//------------------------------------------------------+
		
		
		//----// SEARCH //--------------------------------------+
		V search (string key) override
		{
			int pos = h(key);
			TableEntry<V> aux(key);

			int listPos = table[pos].search(aux);
			
			if (listPos == -1) { throw runtime_error("Key '" + key + "' not found!"); }
			
			return table[pos].get(listPos).value;		
		}
		//------------------------------------------------------+
		
		
		//----// REMOVE //--------------------------------------+
		V remove (string key) override
		{
			int pos = h(key);
			//string info = "Key '" + key + "' not found!";
			TableEntry<V> aux(key);
			
			int listPos = table[pos].search(aux);
			
			if (listPos == -1) { throw runtime_error("Key '" + key + "' not found!"); }

			n--;
			return table[pos].remove(listPos).value;
		}
		//------------------------------------------------------+
		
		
		//----// ENTRIES //-------------------------------------+
		int entries() override
		{
			return n;	
		}
		//------------------------------------------------------+


		/****************************************************************/
		/*                    HashTable (constructor)                   */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método constructor. Reservará memoria dinámica para crear    */
		/* una tabla table de tamaño size, e inicializará los atributos */
		/* n y max de la clase.                                         */
		/*                                                              */
		/* ENTRADA: string key.                                         */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		HashTable (int size)
		{
			this->n = 0;
			this->max = size;
			this->table = new ListLinked<TableEntry<V>>[size];
		}
	
		/****************************************************************/
		/*                   ~HashTable (destructor)                    */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método destructor. Se encargará de liberar la memoria        */
		/* dinámica reservada al crear la tabla table.                  */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		~HashTable ()
		{
			delete[] table;
		}
	
		/****************************************************************/
		/*                          capacity                            */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Devuelve el número total de cubetas de la tabla.             */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: int.                                                 */
		/****************************************************************/

		int capacity ()
		{
			return max;
		}
	
	
		/****************************************************************/
		/*                           operator <<                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga global del operador << para imprimir el contenido */
		/* de la tabla hash por pantalla.                               */
		/*                                                              */
		/* ENTRADA: ostream &out, const HashTable<V> &th.               */
		/*                                                              */
		/* SALIDA: out.                                                 */
		/****************************************************************/

		friend ostream& operator<< (ostream &out, const HashTable<V> &th)
		{
			out << "HashTable [entries: " << (th.n) << ", capacity: " << (th.max) << "]" << endl;
			out << "==============" << endl << endl;
			for (int i = 0; i < (th.max); i++)
			{
				out << "== Cubeta " << i << " ==" << endl << endl;
				out << th.table[i] << endl << endl;
			}
			out << "==============" << endl;
			return out;
		}
	
		/****************************************************************/
		/*                           operator []                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga del operador []. Devuelve el valor                */
		/* correspondiente a key. Si no existe, lanza la excepción      */
		/* runtime_error.                                               */
		/*                                                              */
		/* ENTRADA: string key.                                         */
		/*                                                              */
		/* SALIDA: Devuelve el elemento V situado en la posición pos.   */
		/****************************************************************/
		
		V operator[] (string key)
		{
			return search(key);
		}
};

#endif
