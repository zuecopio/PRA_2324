# PRA_2324_P0
***Práctica 0:** Proyecto "Brazo Robótico"*

### Ejercicio para poner en práctica todas las herramientas vistas en la Práctica 0
  - Terminal Bash
  - Editor Vim
  - Programación en C++
  - Control de versiones con Git/GitHub
  - Automatización de la compilación con Make

### CLASE "BrazoRobotico"

  - *(x,y,z)* 
      > Atributos privados correspondientes a las coordenadas en el espacio 3D en
      la que se encuentra la extemidad del robot.
    
  - *holding*
      > Atributo privado que indique si el robot está sujetando un objeto o no.
    
  - *BrazoRobotico()*
      > Método constructor.
    
  - *getX(), getY(), getZ() & getHolding()*
      > Métodos consultores para los 4 atributos privados.
    
  - *coger()*
      > Método para simular que coge un objeto.
    
  - *soltar()*
      > Método para simular que suelta un objeto.
    
  - *mover( double x, double y, double z )*
      > Metodo para simular que el TCP del brazo robótico se desplaza (x,y,z) unidades
      desde el punto en el espacio en el que se encuentra.

### FICHERO "main.cpp":
  - Simula que el brazo robótico realiza un pick&place sencillo. Todo empieza con la
    inicialización el robot, después se dirige a coger un objeto y para terminar deja
    el objeto en una posición diferente a la del pick.
