/*-----------------------------------------------------+
 |     N O D E . H                                     |
 +-----------------------------------------------------+
 |     Versión     : P01_v1                            | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Implementación de la clase Node   |
 +-----------------------------------------------------*/

#ifndef NODE_H
#define NODE_H

#include <ostream>

#define TRUE 1
#define FALSE 0

template <typename T> 
class Node {
	
	public:
		
		/****************************************************************/
		/*                            data                              */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* El elemento almacenado, de tipo genérico T.                  */
		/*                                                              */
		/****************************************************************/
		
		T data;
		
		/****************************************************************/
		/*                            *next                             */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Puntero al siguiente nodo de la secuencia (o nullptr si es el*/
		/* último nodo de la secuencia).                                */
		/*                                                              */
		/****************************************************************/
		
		Node<T> *next;
		
		/****************************************************************/
		/*                             Node                             */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método constructor. next será nullptr en caso de que no se   */
		/* proporcione.                                                 */
		/*                                                              */
		/****************************************************************/		
		
		Node(T data, Node<T> *next=nullptr)
		{
			this->data = data;
			this->next = next;
		}
		
		/****************************************************************/
		/*                          operator<<                          */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga global del operador << para imprimir una instancia*/
		/* de Node<T> por pantalla. Se limitará a imprimir su atributo  */
		/* data. Recuerda incluir la cabecera <ostream> en el .h.       */
		/*                                                              */
		/****************************************************************/
		
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node)
		{
			out << "Secuencia: ";
   			
  			while (node != nullptr)
  			{
   				out << node.data << " ";
   				node = node.next;
 			}			
			
			return out;
		}
    
};

#endif
