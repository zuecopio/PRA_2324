/*-----------------------------------------------------+
 |     B S T R E E . H                                 |
 +-----------------------------------------------------+
 |     Versión     : P03_v1                            | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PRA-GIIROB                        |     
 |     Descripción : Interfaz genérica BSTree          |
 +-----------------------------------------------------*/

#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"
#include "../PRA_2324_P1/ListLinked.h"

using namespace std;

template <typename T> 
class BSTree {
	
	private:
	
		/****************************************************************/
		/*                       elem (atributo)                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Número de elementos almacenados en el ABB.                   */
		/*                                                              */
		/****************************************************************/

		int nelem;
	
		/****************************************************************/
		/*                       root (atributo)                        */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Nodo raíz del ABB.                                           */
		/*                                                              */
		/****************************************************************/		

		BSNode<T> *root;

		/*-----------------------------------------------------+
 		 |     BUSQUEDA DE ELEMENTOS                           |
 		 +-----------------------------------------------------*/
	
		/****************************************************************/
		/*                      search (recursivo)                      */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método recursivo para la búsqueda elementos en el ABB. Busca */
		/* y devuelve el elemento e de tipo T si se encuentra en el     */
		/* (sub-)árbol cuya raíz es n, de lo contrario lanza una        */
		/* std::runtime_error.                                          */
		/*                                                              */
		/* ENTRADA: BSNode<T>* n, T e.                                  */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		BSNode<T>* search (BSNode<T>* n, T e) const {

			if (n == nullptr) { throw runtime_error("Element not found!"); }
			
			else if (n->elem < e) { return search (n->right, e); }
			
			else if (n->elem > e) { return search (n->left, e); }
			
			else { return n; }
		}

		/*-----------------------------------------------------+
 		 |     INSERCIÓN DE ELEMENTOS                          |
 		 +-----------------------------------------------------*/

		/****************************************************************/
		/*                      insert (recursivo)                      */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método recursivo para la inserción ordenada de elementos.    */
		/* Inserta el elemento e de tipo T de manera ordenada en el     */
		/* (sub-)árbol cuya raíz es n. Devuelve el nodo que encabeza    */
		/* dicho (sub-)árbol modificado. Si el elemento e ya existe,    */
		/* lanza un std::runtime_error.                                 */
		/*                                                              */
		/* ENTRADA: BSNode<T>* n, T e.                                  */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		BSNode<T>* insert (BSNode<T>* n, T e) {

			if (n == nullptr) { return new BSNode (e); }
			
			else if (n->elem == e) { throw runtime_error("Duplicated element!"); }
			
			else if (n->elem < e) { n->right = insert (n->right, e); }
			
			else { n->left = insert (n->left, e); }

			return n;
		}

		/*-----------------------------------------------------+
 		 |     RECORRIDO E IMPRESIÓN DEL ÁRBOL                 |
 		 +-----------------------------------------------------*/

		/****************************************************************/
		/*                   print_preorden (recursivo)                 */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Recorrido preorden del (sub-)árbol cuya raíz es n. Devuelve  */
		/* el órden de introdicción de los nodos.                       */
		/*                                                              */
		/* ENTRADA: ostream &out, BSNode<T>* n.                         */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		void print_preorden (ostream &out, BSNode<T>* n) const {

			if (n != nullptr) {
				out << n->elem << " ";
				print_preorden (out, n->left);
				print_preorden (out, n->right);
			}		
		}
		
		/****************************************************************/
                /*                   print_inorden (recursivo)                  */
                /*--------------------------------------------------------------*/
                /*                                                              */
                /* DESCRIPCION:                                                 */
                /* Recorrido inorden o simétrico del (sub-)árbol cuya raíz es n */
                /* para mostrar a través de out los elementos ordenados de      */
                /* menor a mayor.                                               */
                /*                                                              */
		/* ENTRADA: ostream &out, BSNode<T>* n.                         */
                /*                                                              */
                /* SALIDA: void.                                                */
                /****************************************************************/

                void print_inorden (ostream &out, BSNode<T>* n) const {

                        if (n != nullptr) {
                                print_inorden (out, n->left);
                                out << n->elem << " ";
                                print_inorden (out, n->right);
                        }
                }

                /****************************************************************/
                /*                  print_postorden (recursivo)                 */
                /*--------------------------------------------------------------*/
                /*                                                              */
                /* DESCRIPCION:                                                 */
                /* Recorrido postorden del (sub-)árbol cuya raíz es n. Devuelve */
                /* el órden en el que se deben eliminar los nodos.              */
                /*                                                              */
                /* ENTRADA: ostream &out, BSNode<T>* n.                         */
                /*                                                              */
                /* SALIDA: void.                                                */
                /****************************************************************/

                void print_postorden (ostream &out, BSNode<T>* n) const {

                        if (n != nullptr) {
                                print_postorden (out, n->left);
                                print_postorden (out, n->right);
                                out << n->elem << " ";
                        }
                }

                /****************************************************************/
                /*                   print_anchura (recursivo)                  */
                /*--------------------------------------------------------------*/
                /*                                                              */
                /* DESCRIPCION:                                                 */
                /* Recorrido en anchura del (sub-)árbol cuya raíz es n. Visita  */
		/* los nodos de un nivel antes de bajar al siguiente, necesita  */
                /* necesita una estructura auxiliar.                            */
                /*                                                              */
                /* ENTRADA: ostream &out, BSNode<T>* n.                         */
                /*                                                              */
                /* SALIDA: void.                                                */
                /****************************************************************/
		
                void print_anchura (ostream &out, BSNode<T>* n) const {
                
                      	ListLinked<BSNode<T>*> NodeList; // lista con los nodos vistados
                      	BSNode<T>* node;
                      	
                      	// Q.PUSH(n)
                      	NodeList.insert(NodeList.size(), n);

                        while (!(NodeList.empty())) {
                                               	                    	
                        	// Q.POP() - sacar el primer nodo
                        	node = NodeList.get(0);
                        	NodeList.remove(0);
                        	
                        	if (node != nullptr) {
                        		
                        		// print (node.elem)
                        		out << node->elem << " ";
                        	                        	
                        		// Q.PUSH(n.left)
                        		if (node->left != nullptr) {
                               			NodeList.insert(NodeList.size(), node->left);
                        		}
                                
                              		// Q.PUSH(n.right)
                              		if (node->right != nullptr) {
                               			NodeList.insert(NodeList.size(), node->right);
                        		}
                      		}
                       }
                }

		/*-----------------------------------------------------+
 		 |     ELIMINACIÓN DE ELEMENTOS                        |
 		 +-----------------------------------------------------*/

		/****************************************************************/
		/*                      remove (recursivo)                      */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método recursivo para la eliminación de elementos. Elimina   */
		/* el elemento e del (sub-)árbol cuya raíz es n. Devuelve el    */
		/* nodo que encabeza dicho (sub-)árbol modificado. En caso de   */
		/* eliminar un nodo con dos sucesores (izquierdo y derecho),    */
		/* aplicará la politica de reemplazo por el elemento máximo del */
		/* subárbol izquierdo. Para ello, se apoyará en los métodos     */
		/* privados auxiliares max() y remove_max(). Si el elemento e   */
		/* no existe, lanza un std::runtime_error.                      */
		/*                                                              */
		/* ENTRADA: BSNode<T>* n, T e.                                  */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		BSNode<T>* remove (BSNode<T>* n, T e) {

			if (n == nullptr) { throw runtime_error("Element not found!"); }
			
			else if (n->elem < e) { n->right = remove (n->right, e); }
			
			else if (n->elem > e) { n->left = remove (n->left, e); }
			
			else {

				/* Dos sucesores (izquierdo y derecho) */
				if ((n->left != nullptr) && (n->right != nullptr)) {

					n->elem = max (n->left);
					n->left = remove_max (n->left);
				}

				/* Uno o cero sucesores */
				else {
					n = (n->left != nullptr) ? (n->left) : (n->right);
				}
			}

			return n;

		}

		/****************************************************************/
		/*                        max (recursivo)                       */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método recursivo que devuelve el elemento de máximo valor    */
		/* contenido en el (sub-)árbol cuya raíz es n.                  */
		/*                                                              */
		/* ENTRADA: BSNode<T>* n.                                       */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		T max (BSNode<T>* n) const {

			if (n == nullptr) { throw runtime_error("Element not found!"); }

			else if (n->right != nullptr) { return max (n->right); }

			else { return n->elem; }
		}

		/****************************************************************/
		/*                    remove_max (recursivo)                    */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método recursivo que elimina el elemento de máximo valor     */
		/* contenido en el (sub-)árbol cuya raíz es n.                  */
		/*                                                              */
		/* ENTRADA: BSNode<T>* n.                                       */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		BSNode<T>* remove_max (BSNode<T>* n) {

			if (n->right == nullptr) {

				BSNode<T>* removed = n->left;
				delete n;
				return removed;
			}

			else {

				n->right = remove_max (n->right);
				return n;
			}
		}

		/*-----------------------------------------------------+
 		 |     DESTRUCCIÓN                                     |
 		 +-----------------------------------------------------*/

		/****************************************************************/
		/*                  delete_cascade (recursivo)                  */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método recursivo para liberación de la memoria dinámica      */
		/* ocupada por los objetos de tipo BSNode<T> que conforman el   */
		/* (sub-)árbol cuya raíz es n.                                  */
		/*                                                              */
		/* ENTRADA: BSNode<T>* n.                                       */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		void delete_cascade (BSNode<T>* n) {

			if (n != nullptr) {
				delete_cascade (n->left);
				delete_cascade (n->right);
				delete n;
			}
		}


	public:

		/*-----------------------------------------------------+
 		 |     CREACIÓN Y TAMAÑO                               |
 		 +-----------------------------------------------------*/
	
		/****************************************************************/
		/*                     BSTree (constructor)                     */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método constructor. Crea un ABB vacío.                       */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		BSTree () {

			this->nelem = 0;
			this->root = nullptr;
		}
	
		/****************************************************************/
		/*                            size                              */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Devuelve el número de elementos nelem del ABB.               */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: int.                                                 */
		/****************************************************************/

		int size () const {

			return nelem;
		}

		/*-----------------------------------------------------+
 		 |     BUSQUEDA DE ELEMENTOS                           |
 		 +-----------------------------------------------------*/

		/****************************************************************/
		/*                      search (lanzacera)                      */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Busca y devuelve el elemento e de tipo T en el ABB. Actúa    */
		/* como método lanzadera del método privado recursivo           */
		/* search(BSNode<T>* n, T e). Notar que deberá devolver el      */
		/* elemento contenido por el nodo devuelto por el método        */
		/* privado.                                                     */
		/*                                                              */
		/* ENTRADA: T e.                                                */
		/*                                                              */
		/* SALIDA: T e.                                                 */
		/****************************************************************/

		T search (T e) const {

			return (search (root, e))->elem;
		}

		/****************************************************************/
		/*                          operator []                         */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga del operador[]. Actúa como interfaz al método     */
		/* search( T e ).                                               */
		/*                                                              */
		/* ENTRADA: T e.                                                */
		/*                                                              */
		/* SALIDA: T e.                                                 */
		/****************************************************************/

		T operator[] (T e) const {

			return search (e);
		}

		/*-----------------------------------------------------+
 		 |     INSERCIÓN DE ELEMENTOS                          |
 		 +-----------------------------------------------------*/

		/****************************************************************/
		/*                      insert (lanzacera)                      */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Inserta el elemento e de tipo T de manera ordenada en el ABB.*/
		/* Actúa como método lanzadera del método privado recursivo     */
		/* insert(BSNode<T>* n, T e).                                   */
		/*                                                              */
		/* ENTRADA: T e.                                                */
		/*                                                              */
		/* SALIDA: T e.                                                 */
		/****************************************************************/

		void insert (T e) {

			root = insert (root, e);
			nelem++;
		}

		/*-----------------------------------------------------+
 		 |     RECORRIDO E IMPRESIÓN DEL ÁRBOL                 |
 		 +-----------------------------------------------------*/

		/****************************************************************/
		/*                    operator << (lanzacera)                   */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga del operador << para mostrar a través de out los  */
		/* contenidos del ABB bst, realizando un recorrido inorden o    */
		/* simétrico del árbol para mostrar los elementos ordenados de  */
		/* menor a mayor. Delega en el método privado recursivo         */
		/* print_inorder().                                             */
		/*                                                              */
		/* ENTRADA: ostream &out, const BSTree<T> &bst.                 */
		/*                                                              */
		/* SALIDA: out.                                                 */
		/****************************************************************/

		friend ostream& operator<< (ostream &out, const BSTree<T> &bst) {

			out << "PREORDEN  : ";
			bst.print_preorden (out, bst.root);
			out << endl;

			out << "INORDEN   : ";
                        bst.print_inorden (out, bst.root);
                        out << endl;

			out << "POSTORDEN : ";
                        bst.print_postorden (out, bst.root);
                        out << endl;
                        
                        out << "ANCHURA   : ";
                        bst.print_anchura (out, bst.root);
                        out << endl;
			
			return out;
		}

		/*-----------------------------------------------------+
 		 |     ELIMINACIÓN DE ELEMENTOS                        |
 		 +-----------------------------------------------------*/

		/****************************************************************/
		/*                      remove (lanzacera)                      */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Elimina el elemento e de tipo T del ABB. Actúa como método   */
		/* lanzadera del método privado recursivo                       */
		/* remove (BSNode<T>* n, T e).                                  */
		/*                                                              */
		/* ENTRADA: T e.                                                */
		/*                                                              */
		/* SALIDA: out.                                                 */
		/****************************************************************/

		void remove (T e) {

			root = remove (root, e);
			nelem--;
		}

		/*-----------------------------------------------------+
 		 |     DESTRUCCIÓN                                     |
 		 +-----------------------------------------------------*/

		/****************************************************************/
		/*                      ~BSTree (destructor)                    */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método destructor. Delega en el método privado recursivo     */
		/* delete_cascade().                                            */
		/*                                                              */
		/* ENTRADA: void.                                               */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		~ BSTree () {

			delete_cascade (root);
		}
};

#endif
