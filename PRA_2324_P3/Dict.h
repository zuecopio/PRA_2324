/*-----------------------------------------------------+
 |     D I C T . H                                     |
 +-----------------------------------------------------+
 |     Versión     : P03_v1                            | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Interfaz genérica Dict            |
 +-----------------------------------------------------*/

#ifndef DICT_H
#define DICT_H

#include <string>

using namespace std;

template <typename V> 
class Dict {
	
	public:
	
		/****************************************************************/
		/*                           insert                             */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Inserta el par key->value en el diccionario. Lanza una       */
		/* excepción std::runtime_error si key ya existe en el          */
		/* diccionario.                                                 */
		/*                                                              */
		/* ENTRADA: string key, V value.                                */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		virtual void insert( string key, V value ) = 0;
	
		/****************************************************************/
		/*                           search                             */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Busca el valor correspondiente a key. Devuelve el valor      */
		/* value asociado si key está en el diccionario. Si no se       */
		/* encuentra, lanza una excepción std::runtime_error.           */
		/*                                                              */
		/* ENTRADA: string key.                                         */
		/*                                                              */
		/* SALIDA: Devuelve el elemento V correspondiente a key.        */
		/****************************************************************/		

		virtual V search( string key ) = 0; 
	
		/****************************************************************/
		/*                           remove                             */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Elimina el par key->value si se encuentra en el diccionario. */
		/* Si no se encuentra, lanza una excepción std::runtime_error.  */
		/*                                                              */
		/* ENTRADA: int pos.                                            */
		/*                                                              */
		/* SALIDA: Devuelve el elemento V eliminado.                    */
		/****************************************************************/

		virtual V remove( string key ) = 0;
	
		/****************************************************************/
		/*                           entries                            */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Devuelve el número de elementos que tiene el Diccionario.    */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: int (cantidad de elementos).                         */
		/****************************************************************/

		virtual int entries() = 0;
};

#endif
