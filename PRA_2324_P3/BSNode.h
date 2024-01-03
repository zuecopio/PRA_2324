/*-----------------------------------------------------+
 |     B S N O D E . H                                 |
 +-----------------------------------------------------+
 |     Versión     : P03_v1                            | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Interfaz genérica BSNode          |
 +-----------------------------------------------------*/

#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

using namespace std;

template <typename T> 
class BSNode {
	
	public:
	
		/****************************************************************/
		/*                       elem (atributo)                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* El elemento de tipo T almacenado en el nodo.                 */
		/*                                                              */
		/****************************************************************/

		T elem;
	
		/****************************************************************/
		/*                       left (atributo)                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Puntero al nodo sucesor izquierdo.                           */
		/*                                                              */
		/****************************************************************/		

		BSNode<T>* left; 
	
		/****************************************************************/
		/*                      rigth (atributo)                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Puntero al nodo sucesor derecho.                             */
		/*                                                              */
		/****************************************************************/

		BSNode<T>* right;
	
		/****************************************************************/
		/*                     BSNode (constructor)                     */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método constructor que crea un BSNode con el elemento elem y */
		/* los punteros a los nodos sucesores left y right              */
		/* proporcionados (nulos por defecto).                          */
		/*                                                              */
		/* ENTRADA: T elem, BSNode<T>* left, BSNode<T>* right.          */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		BSNode (T elem, BSNode<T>* left=nullptr, BSNode<T>* right=nullptr) {

			this->elem = elem;
			this->left = left;
			this->right = right;
		}
	
		/****************************************************************/
		/*                           operator <<                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga global del operador << para imprimir el nodo por  */
		/* pantalla. Por simplicidad, puedes limitarte a imprimir el    */
		/* atributo elem.                                               */
		/*                                                              */
		/* ENTRADA: T elem, BSNode<T>* left, BSNode<T>* right.          */
		/*                                                              */
		/* SALIDA: out.                                                 */
		/****************************************************************/

		friend ostream& operator<<(ostream &out, const BSNode<T> &bsn) {

			out << bsn.elem;

			return out;
		}
};

#endif