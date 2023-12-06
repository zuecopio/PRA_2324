/*-----------------------------------------------------+
 |     L I S T A R R A Y. H                            |
 +-----------------------------------------------------+
 |     Versión     : P01_v1                            | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Implantación clase ListArray      |
 +-----------------------------------------------------*/

#ifndef LISTARRAY_H
#define LISTARRAY_H


#include "List.h"
#include <ostream>
#include <exception>
#include <string>

#define TRUE 1
#define FALSE 0

std::string info = "Posición inválida!";

template <typename T> 
class ListArray : public List<T> {
 
	private:
	
		/****************************************************************/
		/*                            *arr                              */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Puntero al inicio del array que almacenará los elementos de  */
		/* la lista de forma contigua. Estos elementos son de tipo T    */
		/* genérico.                                                    */
		/*                                                              */
		/****************************************************************/
		
		T *arr;
	
		/****************************************************************/
		/*                            max                               */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Tamaño actual del array. Podrá alterarse durante la vida de  */
		/* la lista, en caso necesario (ver método resize(int)).        */
		/*                                                              */
		/****************************************************************/
		
		int max;
	
		/****************************************************************/
		/*                             n                                */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Número de elementos que contiene la lista.                   */
		/*                                                              */
		/****************************************************************/
		
		int n;
	
		/****************************************************************/
		/*                          MINSIZE                             */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Tamaño mínimo del array. Deberá inicializarse a 2.           */
		/*                                                              */
		/****************************************************************/
		
		static const int MINSIZE = 2;
	
		/****************************************************************/
		/*                          resize                              */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método privado que se encargará de redimensionar el array al */
		/* tamaño especificado, con el objetivo de incrementar su       */
		/* capacidad (si está lleno), o bien para reducirla (si está    */
		/* "demasiado vacío"). Ver nota más abajo para más detalles.    */
		/*                                                              */
		/* ENTRADA: int new_size.                                       */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/
		
		void resize(int new_size)
		{
			max = new_size;
			n = new_size;
		} 

	public:
	
		//----// INSERT //--------------------------------------+
		void insert(int pos, T e) override
		{
			if ( !(pos < 0 || pos > size()) )
			{				
				if (pos == 0) { prepend(e); }
				
				else if (pos == size()) { append(e); }
				
				else
				{
					int i, j, new_size = n + 1;
			
					T *aux = new T[new_size];
			
					for (i = 0, j = 0; i < new_size; i ++)
					{
						if (pos == i) { aux[i] = e; }
						else { aux[i] = arr[j]; j++; }
					}
					
					delete[] arr;
					arr = aux;
					resize(new_size);
				}
			}
			else { throw std::out_of_range(info); }
		}
		//------------------------------------------------------+



		//----// APPEND //--------------------------------------+
		void append(T e) override
		{
			// pos = size()
			
			int new_size = size() + 1;
			
			T *aux = new T[new_size];
						
			for (int i = 0; i < size(); i++)
			{
				aux[i] = arr[i];
			}
			
			aux[size()] = e;
			
			delete[] arr;
			arr = aux;
			resize(new_size);
		}
		//------------------------------------------------------+



		//----// PREPEND //-------------------------------------+
		void prepend(T e) override
		{
			// pos = 0
			
			int new_size;
			
			(n == 0) ? (new_size = 1) : (new_size = size() + 1);
			
			T *aux = new T[new_size];
			
			aux[0] = e;
			
			if (n != 0)
			{
				for (int i = 0; i < size(); i++)
				{
					aux[i+1] = arr[i];
				}
			}
			delete[] arr;
			arr = aux;
			resize(new_size);
		}
		//------------------------------------------------------+
		
		

		//----// REMOVE //--------------------------------------+
		T remove(int pos) override
		{
			T removed;
			if ( (pos >= 0 && pos < size()) )
			{
				int i, j, new_size = size() - 1;
				
				T *aux = new T[new_size];
				
				for (i = 0, j = 0; i < size(); i++)
				{
					if (pos == i) { removed = arr[i]; }
					else { aux[j] = arr[i]; j++; }
				}
				delete[] arr;
				arr = aux;
				resize(new_size);
			}
			else { throw std::out_of_range(info); }
			
			return removed;	
		}
		//------------------------------------------------------+
		
		
		
		//----// GET //-----------------------------------------+
		T get(int pos) override
		{
			if ( (pos >= 0 && pos < size()) )
			{
				return arr[pos];
			}
			else { throw std::out_of_range(info); }
		}
		//------------------------------------------------------+
		
		

		//----// SEARCH //--------------------------------------+
		int search(T e) override
		{
			int i = 0, posi;
			while ( (arr[i] != e) && (i < size()) ) { i++; }
			(i == size()) ? (posi = -1) : (posi = i);
			
			return posi;
		}
		//------------------------------------------------------+
		
		

		//----// EMPTY //---------------------------------------+
		bool empty() override
		{
			bool answer;
			(n == 0) ? (answer = TRUE) : (answer = FALSE);
			
			return answer;			
		}
		//------------------------------------------------------+
				
				
		
		//----// SIZE //----------------------------------------+
		int size() override
		{
			return max;
		}
		//------------------------------------------------------+
		
		
	
		/****************************************************************/
		/*                         ListArray                            */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método constructor sin argumentos. Se encargará de reservar  */
		/* memoria dinámica para crear un array de MINSIZE elementos de */
		/* tipo T, además de inicializar el resto de atributos de       */
		/* instancia.                                                   */
		/*                                                              */
		/****************************************************************/

		ListArray()
		{
			arr = new T[MINSIZE];
			max = MINSIZE;
			n = 0;
		}
	
		/****************************************************************/
		/*                        ~ListArray                            */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método destructor. Se encargará de liberar la memoria        */
		/* dinámica reservada.                                          */
		/*                                                              */
		/****************************************************************/
		
        	~ListArray()
        	{
        		delete[] arr;
        	}
	
		/****************************************************************/
		/*                        operator []                           */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga del operador []. Devuelve el elemento situado en  */
		/* la posición pos. Lanza una excepción std::out_of_range si la */
		/* posición no es válida (fuera del intervalo [0, size()-1]).   */
		/*                                                              */
		/* ENTRADA: int pos.                                            */
		/*                                                              */
		/* SALIDA: Devuelve el elemento T situado en la posición pos.   */
		/****************************************************************/
		
        	T operator[](int pos)
        	{
        		return get(pos);
		}
	
		/****************************************************************/
		/*                         operator <<                          */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga global del operador << para imprimir una instancia*/
		/* de ListArray<T> por pantalla. Incluir la cabecera  <ostream> */
		/* en el .h.                                                    */
		/*                                                              */
		/* ENTRADA: std::ostream &out, const ListArray<T> &list.        */
		/*                                                              */
		/* SALIDA: Imprime instancia.                                   */
		/****************************************************************/
		
 		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list)
 		{
 			out << "List => [";
 			for (int i = 0; i < list.max; i++)
 			{
 				(list.n == 0) ? (out << "") : (out << std::endl << "  " << list.arr[i]);
 				if ((i == (list.max-1)) && (list.n != 0)) { out << std::endl; }
 			}
 			out << "]";
 			
 			return out;
 		}
};

#endif
