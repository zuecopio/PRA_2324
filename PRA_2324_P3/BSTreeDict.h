/*-----------------------------------------------------+
 |     B S T R E E D I C T . H                         |
 +-----------------------------------------------------+
 |     Versión     : P03_v1                            | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Declaración e implementación de   |
 |                   la clase BSTreeDict               |
 +-----------------------------------------------------*/

#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

using namespace std;

template <typename V> 
class BSTreeDict : public Dict<V> {
	
	private:
	
		/****************************************************************/
		/*                       elem (atributo)                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* ABB con elementos de tipo TableEntry<V> para gestionar los   */
		/* elementos de un diccionario.                                 */
		/*                                                              */
		/****************************************************************/

		BSTree<TableEntry<V>>* tree;

	public:

		//----// INSERT //--------------------------------------+
		void insert (string key, V value) override
		{
			tree->insert (TableEntry<V> (key, value));
		}
		//------------------------------------------------------+
		
		
		//----// SEARCH //--------------------------------------+
		V search (string key) override
		{
			return tree->search (TableEntry<V> (key)).value;
		}
		//------------------------------------------------------+
		
		
		//----// REMOVE //--------------------------------------+
		V remove (string key) override
		{
			V removed = tree->search (TableEntry<V> (key)).value;
			tree->remove (TableEntry<V> (key));
			return removed;
		}
		//------------------------------------------------------+
		
		
		//----// ENTRIES //-------------------------------------+
		int entries() override
		{
			return tree->size ();	
		}
		//------------------------------------------------------+


		/****************************************************************/
		/*                   BSTreeDict (constructor)                   */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Constructor. Crea un ABB vacío con memoria dinámica.         */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		BSTreeDict () {

			tree = new BSTree<TableEntry<V>>;
		}

		/****************************************************************/
		/*                    ~BSTreeDict (destructor)                  */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método destructor. Se encargará de liberar la memoria        */
		/* dinámica ocupada por el ABB tree.                            */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		~ BSTreeDict () {

			delete tree;
		}

		/****************************************************************/
		/*                          operator <<                         */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga global del operador << para imprimir el contenido */
		/* del Diccionario por pantalla.                                */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		friend ostream& operator<< (ostream &out, const BSTreeDict<V> &bs) {

			return out << *bs.tree << endl;
		}

		/****************************************************************/
		/*                          operator []                         */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga del operador[]. Actúa como interfaz al método de  */
		/* interfaz heredado search(string key).                        */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		V operator[] (string key) {

			return search (key);
		}
};

#endif
