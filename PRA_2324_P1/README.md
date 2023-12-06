# PRA_2324_P1
***Práctica 1:** Interfaz genérica para una estructura de datos lineal*

## PARTE 1: EDL Lista genérica

### Interfaz ```List<T>```
Es una clase abstracta pura y genérica (templatizada). Consta de 8 métodos públicos que serán definidos en las propias clases derivades mediante ```overrride```. Explicación de cada método en el propio .h. 

### Clase ```ListArray<T>```
La clase ```ListArray<T>``` es una clase derivada de la interfaz genérica ```List<T>```. La clase implementa los métodos de dicha interfaz, definiendolos mediante la orden ```override```. ```ListArray<T>``` implementará la estructura de datos lista mediante una representación de secuencias en memoria contigua (con arrays). 
Consta de 4 atributos privados, un método privado y 4 métodos públicos a los que hay que sumar los heredados de ```List<T>```. Explicación de los atributos y los métodos en el propio .h. 

### Clase ```Node<T>```
Se trata de una implementación alternativa de la interfaz ```List<T>```, basada en representación de secuencias en memoria dispersa, mediante nodos enlazados. Para ello, es necesario generar una implementación genérica de nodo, llamada ```Node<T>```, para almacenar elementos de un tipo de datos genérico T.
Consta de 2 atributos y 2 métodos públicos. Explicación de los atributos y los métodos en el propio .h. 

### Clase ```ListLinked<T>```
Segunda implementación de la interfaz ```List<T>```. En esta ocasión, se trata de ```ListLinked<T>```, una clase derivada de ```List<T>``` que implementará la estructura de datos lista mediante una representación de secuencias en memoria dispersa (con nodos enlazados).
Consta de 2 atributos privados y 4 métodos públicos. A todo esto hay que sumar los métodos heredados de ```List<T>``` y los atributos y métodos heredados de ```Node<T>```. Explicación de los atributos y los métodos en el propio .h. 

## PARTE 2: Jerarquía de clases para una app de dibujo 2D
Trabajo todavía en proceso...
