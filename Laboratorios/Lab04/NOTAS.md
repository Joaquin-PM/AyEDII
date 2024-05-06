### Para pensar: ¿Qué valor tendrá la variable *"y"* luego de ejecutar el siguiente código?

~~~c
int x = 3;
int y = 10;
y = *(&x);
~~~
Luego de ejecutar este código, la variable *"y"* valdra 3, Es decir lo mismo que la variable *"x"*.

## Ejercicio 2a)
### ¿Qué valor se muestra por pantalla?¿Coincide con el programa en el lenguaje del teórico?

Muestra el valor 0, parece que "res" no cambió de valor, claramente 
no coincide con el teórico que mostraria el valor 10.

## Ejercicio 2b)
### ¿Se muestra el valor correcto?

Si, ahora muestra el valor correcto.

## Ejercicio 2c)
### ¿El parámetro int *y de absolute() es de tipo in, de tipo out o de tipo in/out?

Al declarar **absolute(int x, int \*y)** estamos haciendo **paso por referencia a la variable "y"**. Es decir que el "procedimiento" toma la **dirección de memoria de *"y"*** para asi poder modificarla, pero **NO** modifica la variable **"\*y"** que es un puntero a un entero, solo modifica lo que este dentro de esa direccion de memoria a la que apunta, es decir el valor de la variable **"y"**.
De esta manera decimos que el **parámetro int \*y** es de tipo **in**.

### ¿Qué tipo de parámetros tiene disponibles C para sus funciones?

En C, los parámetros de una función son de **paso por valor** de forma predeterminada, lo que significa que se crea una copia del valor de la variable pasada. Esto lo considero como una modalidad de tipo **in** porque la función no modifica el valor original.

Pero al usar punteros se puede lograr efectos similares a **out** o **in/out**, porque pasar un puntero como parámetro a una función te permite modificar posiciones de memoria y asi modificar el valor de la variable original.
Tal vez se pueda considerar el paso de parámetros por punteros como una forma de **out** o **in/out**.

## Ejercicio 3)
### ¿Funciona más rápido la versión con punteros? ¿Por qué ahora son más eficientes los intercambios?



## Para pensar: Sea p un puntero ¿Cuál sería el resultado de la expresión &p?

El valor de &p seria la dirección de memoria donde esta alojado la variable p de tipo puntero.

## Ejercicio4c)

### ¿La suma de los miembros coincide con el total? ¿El tamaño del campo name depende del nombre que contiene?
La suma no coincide con el total, el tamaño del campo name no depende del nombre sino del TIPO que en este caso es un char[30].

### ¿Hay algo raro en las direcciones de memoria?
Si, el campo name esta en la misma dirección de memoria que el la estructura data_t, a diferencia de los otros campos que estan en direcciones distintas.

## Ejercicio5b)
### ¿El diseño del TAD logra encapsulamiento? ¿Por qué sí? ¿Por qué no?
No lo logra, ya que hay una funcion para manejar el TAD que esta implementada en el archivo principal main.c, por lo tanto se puede ver como esta implementado el TAD ademas en la especificación se puede ver como es la estructura del nuevo TAD todo esto hace que no sea "abstracto".

## Ejercicio5d)
### ¿Laimplementación logra encapsulamiento?
Ahora SI logra el encapsulamiento, viendo el archivo main.c y la especificación pair.h no puedo saber nada de como esta implementado ese TAD.

## Ejercicio 5e)
### ¿Qué diferencia hay entre la especificación anterior y la que se encuentra en el pair.h de la carpeta pair_d-pointer?
No hay muchisima diferencia, solo se renombro al tipo int como elem, la ventaja podria ser que ahora es mas facil cambiar el tipo concreto que maneja el TAD, solo cambiando el tipo al cual llamamos elem.




