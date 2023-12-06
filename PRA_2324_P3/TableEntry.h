/*-----------------------------------------------------+
 |     T A B L E E N T R Y . H                         |
 +-----------------------------------------------------+
 |     Versión     : P03_v1                            | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Declaración e implementación de   |
 |                   la clase TableEntry               |
 +-----------------------------------------------------*/

#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

using namespace std;

template <typename V> 
class TableEntry {
	
	public:
	
		/****************************************************************/
		/*                        key (atributo)                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* El elemento clave del par.                                   */
		/*                                                              */
		/****************************************************************/

		string key;
	
		/****************************************************************/
		/*                       value (atributo)                       */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* El elemento valor del par.                                   */
		/*                                                              */
		/****************************************************************/		

		V value;
	
		/****************************************************************/
		/*                  TableEntry (constructor 1)                  */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método constructor con el par clave->valor.                  */
		/*                                                              */
		/* ENTRADA: string key, V value.                                */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		TableEntry( string key, V value )
		{
			this->key = key;
			this->value = value;
		}
	
		/****************************************************************/
		/*                  TableEntry (constructor 2)                  */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Crea una entrada solo con clave (sin valor).                 */
		/*                                                              */
		/* ENTRADA: string key.                                         */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		TableEntry( string key )
		{
			this->key = key;
			this->value = NULL;
		}
	
		/****************************************************************/
		/*                  TableEntry (constructor 3)                  */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Crea una entrada con la clave "" (cadena vacía) y sin valor. */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		TableEntry()
		{
			this->key = NULL;
			this->value = NULL;
		}
	
		/****************************************************************/
		/*                           operator ==                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga global del operador == para determinar que dos    */
		/* instancias de TableEntry son iguales solo si comparten la    */
		/* misma clave (con independencia del valor).                   */
		/*                                                              */
		/* ENTRADA: const TableEntry<V> &te1, const TableEntry<V> &te2. */
		/*                                                              */
		/* SALIDA: bool.                                                */
		/****************************************************************/

		friend bool operator==( const TableEntry<V> &te1, const TableEntry<V> &te2 )
		{
			bool result;
			(te1.key.compare(te2.key) == 0) ? (result = 1) : (result = 0);
			return result;
		}
	
		/****************************************************************/
		/*                           operator !=                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga global del operador != para determinar que dos    */
		/* instancias de TableEntry son diferentes solo si sus claves   */
		/* son distintas (con independencia del valor).                 */
		/*                                                              */
		/* ENTRADA: const TableEntry<V> &te1, const TableEntry<V> &te2. */
		/*                                                              */
		/* SALIDA: bool.                                                */
		/****************************************************************/

		friend bool operator!=( const TableEntry<V> &te1, const TableEntry<V> &te2 )
		{
			bool result;
			(te1.key.compare(te2.key) != 0) ? (result = 1) : (result = 0);
			return result;
		}
	
		/****************************************************************/
		/*                           operator <<                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga global del operador << para imprimir el contenido */
		/* de la entrada (par clave->valor) por pantalla.               */
		/*                                                              */
		/* ENTRADA: ostream &out, const TableEntry<V> &te.              */
		/*                                                              */
		/* SALIDA: out.                                                 */
		/****************************************************************/

		friend ostream& operator<<( ostream &out, const TableEntry<V> &te )
		{
			out << "('" << te.key << "' => " << te.value << ")";
			return out;
		}
};

#endif
