/*-----------------------------------------------------+
 |     L I S T . H                                     |
 +-----------------------------------------------------+
 |     Versión     : P01_v1                            | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Interfaz genérica List            |
 +-----------------------------------------------------*/

#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {
	
	public:
	
		/****************************************************************/
		/*                           insert                             */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Inserta el elemento e en la posición pos. Lanza una excepción*/
		/* std::out_of_range si la posición pos no es válida (fuera del */
		/* intervalo [0, size()]).                                      */
		/*                                                              */
		/* ENTRADA: int pos, T e.                                       */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		virtual void insert( int pos, T e ) = 0;
	
		/****************************************************************/
		/*                           append                             */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Inserta el elemento e al final de la lista.                  */
		/*                                                              */
		/* ENTRADA: T e.                                                */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/	

		virtual void append( T e ) = 0;
	
		/****************************************************************/
		/*                           prepend                            */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Inserta el elemento e al principio de la lista.              */
		/*                                                              */
		/* ENTRADA: T e.                                                */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		virtual void prepend( T e ) = 0;
	
		/****************************************************************/
		/*                           remove                             */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Elimina y devuelve el elemento situado en la posición pos.   */
		/* Lanza una excepción std::out_of_range si la posición no es   */
		/* válida (fuera del intervalo [0, size()-1]).                  */
		/*                                                              */
		/* ENTRADA: int pos.                                            */
		/*                                                              */
		/* SALIDA: Devuelve el elemento T situado en la posición pos.   */
		/****************************************************************/

		virtual T remove( int pos ) = 0;
	
		/****************************************************************/
		/*                             get                              */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Devuelve el elemento situado en la posición pos. Lanza una   */
		/* excepción std::out_of_range si la posición no es válida      */
		/* (fuera del intervalo [0, size()-1]).                         */
		/*                                                              */
		/* ENTRADA: int pos.                                            */
		/*                                                              */
		/* SALIDA: Devuelve el elemento T situado en la posición pos.   */
		/****************************************************************/

		virtual T get( int pos ) = 0;
	
		/****************************************************************/
		/*                           search                             */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Devuelve la posición en la que se encuentra la primera       */
		/* ocurrencia del elemento e, o -1 si no se encuentra.          */
		/*                                                              */
		/* ENTRADA: T e.                                                */
		/*                                                              */
		/* SALIDA: Posición int donde se encuentra el elemento e, o -1  */
		/*         si no lo encuentra.                                  */
		/****************************************************************/		

		virtual int search( T e ) = 0; 
	
		/****************************************************************/
		/*                           empty                              */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Indica si la lista está vacía.                               */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: TRUE = 1, FALSE = 0.                                 */
		/****************************************************************/

		virtual bool empty() = 0;
	
		/****************************************************************/
		/*                            size                              */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Devuelve el número de elementos de la lista.                 */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: int size.                                            */
		/****************************************************************/

		virtual int size() = 0;
};

#endif
