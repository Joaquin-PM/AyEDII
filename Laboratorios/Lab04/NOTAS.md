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



