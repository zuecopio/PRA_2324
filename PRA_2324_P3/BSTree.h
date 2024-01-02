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
#include <stdexcepr>
#include <BSNode.h>

using namespace std;

template <typename V> 
class BSTree {
	
	private:
	
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

		BSNode<T>* search (BSNode<T>* n, T e) const;

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

		BSNode<T>* insert (BSNode<T>* n, T e);

		/****************************************************************/
		/*                   print_inorder (recursivo)                  */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Recorrido inorden o simétrico del (sub-)árbol cuya raíz es n */
		/* para mostrar a través de out los elementos ordenados de      */
		/* menor a mayor.                                               */
		/*                                                              */
		/* ENTRADA: BSNode<T>* n, T e.                                  */
		/*                                                              */
		/* SALIDA: void.                                                */
		/****************************************************************/

		void print_inorder (std::ostream &out, BSNode<T> n) const;

		/****************************************************************/
		/*                   print_inorder (recursivo)                  */
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

		BSNode<T>* remove (BSNode<T>* n, T e);

		/****************************************************************/
		/*                          max (recursivo)                     */
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

		T max (BSNode<T>* n) const;

		/****************************************************************/
		/*                     remove_max (recursivo)                   */
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

		BSNode<T>* remove_max (BSNode<T>* n);

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

		void delete_cascade (BSNode<T>* n);


	public:
	
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

		BSTree ();
	
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

		int size () const;

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

		T operator[] (T e) const;

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

		T search (T e) const;

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

		void insert (T e);

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

		friend ostream& operator<< (ostream &out, const BSTree<T> &bst);

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

		void remove (T e);

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

		BSNode<T>* remove_max (BSNode<T>* n);
};

#endif