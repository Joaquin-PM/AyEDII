# Algoritmos y Estructuras de Datos II
 
### Laboratorio 1: Ordenación
- Revisión 2024: Marco Rocchietti
- 21 de marzo 2024

## Objetivos
1. Introducir las cadenas en C.
2. Repaso de **typedef**.
3. Implementar el algoritmo de ordenación por inserción (*insertion-sort*).
4. Implementar el algoritmo de ordenación rápida (*quick-sort*).
5. Comparar desempeño de los algoritmos *selection-sort*, *insertion-sort* y *quick-sort* en distintos ejemplos.
6. Lectura y comprensión del código entregado por la cátedra.
7. Trabajar con implementaciones opacas de funciones leyendo su documentación.
8. Abstraer la noción de orden.
9. Usar procedimientos en C.
10. Uso de funciones locales en módulos en C.

## Ejercicio 0: Cadenas
Las cadenas en C se pueden pensar como arreglos de caracteres (más adelante veremos que también son
punteros, pero por ahora... usamos arreglos). Los caracteres son valores del tipo ***char*** (que representa
exactamente un caracter de 1 *byte*), entonces para guardar un *string* en C se puede usar el siguiente arreglo:
~~~c
char cadena[5];
~~~
En este ejemplo el arreglo *cadena* tiene capacidad para guardar un *string* de hasta 4 caracteres de
longitud. Esto es así porque toda cadena en C debe terminar con el caracter ***'\0'*** por lo cual ya tenemos un
lugar ocupado. Esta convención permite saber dónde termina la cadena independientemente de la capacidad del
arreglo. Entonces, se puede almacenar en *cadena* una palabra con longitud de entre uno y cuatro caracteres,
pero incluso también se puede guardar una palabra vacía (en ese caso **cadena[0] = *'\0'***). Si queremos
armar el string con la palabra *“hola”* podemos hacer:
~~~c
char cadena[5]={'h', 'o', 'l', 'a', '\0'};
printf("cadena: %s\n", cadena);
~~~
Es muy importante no olvidarse de poner el ***'\0'*** final ya que de lo contrario **printf()** va a recorrer a
***cadena[]*** por fuera de su rango hasta que aparezca un ***'\0'*** y al acceder a memoria inválida se producirá
eventualmente una violación de segmento(*segmentation fault*). Notar que no hay ningún problema en hacer
~~~c
char cadena[10]={'h', 'o', 'l', 'a', '\0'};
printf("cadena: %s\n", cadena);
~~~
ya que simplemente estamos usando cinco de los diez elementos del arreglo. Como el  ***'\0'*** se encuentra en
***cadena[4]***, la función **printf()** en el ejemplo anterior va a mostrar los caracteres que hay hasta esa posición
(sin incluirla).

Otra forma más cómoda de armar el string con la palabra *“hola”* es hacer algo como:
~~~c
char cadena[10]="hola";
printf("cadena: %s\n", cadena);
~~~
En este caso el caracter ***'\0'*** se agrega implícitamente en el arreglo ***cadena***. Para no tener que contar la
cantidad de caracteres que necesitamos se puede definir una cadena directamente haciendo:
~~~c
char cadena[]="hola mundo!";
printf("cadena: %s\n", cadena);
~~~
el contenido del array es el siguiente:
INSERTAR CADENA

Cabe destacar que todas estas maneras de armar strings solo son válidas al momento de inicialización del
arreglo. Si hacemos
~~~c
char cadena[]="hola mundo!";
cadena = "chau mundo!";
printf("cadena: %s\n", cadena);
~~~
El resultado va a ser un error de compilación. En este ejercicio vamos a trabajar con cadenas guardadas en
arreglos que tienen un tamaño fijo. Vamos a definir un tipo para estas cadenas usando **typedef**. A modo de
repaso, lo que hace **typedef** es dar un nombre nuevo a un tipo que ya existe en C. Entonces por ejemplo si
queremos definir el tipo ***natural*** para los números positivos:
~~~c
typedef unsigned int natural;
~~~
de esta manera cuando declaremos una variable del tipo ***natural*** la variable va a ser equivalente a una variable
del tipo ***unsigned int***. La sintaxis entonces es:
~~~c
typedef <tipo-existente> <nuevo-tipo>;
~~~
Para definir el tipo nuevo ***fixstring*** hay que usar una sintaxis más extraña:
~~~c
#define FIXSTRING_MAX 100
typedef char fixtring [FIXSTRING_MAX];
~~~
Lo que se hace aquí es definir el tipo ***fixstring*** como el tipo de los arreglos de elementos de tipo ***char***
que tienen una capacidad de **FIXSTRING_MAX** elementos. O sea que si declaramos
~~~c
fixstring s;
~~~
es lo mismo que declarar
~~~c
char s[FIXSTRING_MAX];
~~~
Dentro de la carpeta **ej0** van a encontrar los archivos **fixstring.h**, **fixstring.c** y **main.c**. Deben
implementar en **fixstring.c** las funciones:
~~~c
unsigned int fstring_length(fixstring s);
~~~
~~~c
bool fstring_eq(fixstring s1, fixstring s2);
~~~
~~~c
bool fstring_less_eq(fixstring s1, fixstring s2);
~~~
La función **fstring_length()** devuelve la longitud de la cadena guardada en el parámetro ***s***, la función
**fstring_eq()** indica si las cadenas ***s1*** y ***s2*** son iguales(contienen la misma cadena), mientras que
**fstring_less_eq()** indica si la cadena guardada en ***s1*** es menor o igual que la guardada en ***s2*** 
en el sentidodel orden alfabético. No se permite usar librerías de C como **string.h** ni **strings.h**. Una vez
implementadas pueden probarlas compilando junto con **main.c**.

## Ejercicio 1: Insertion Sort
Dentro de la carpeta **ej1** se encuentran los siguientes archivos

| Archivo             | Descripción |
|---------------------|-------------|
| **array_helpers.h** | Prototipos y descripciones de la funciones auxiliares para manipular arreglos.|
| **array_helpers.c** | Implementaciones de las funciones de la librería array_helpers|
| **sort_helpers.h**  | Prototipos y descripciones de las funciones ***goes_before()***, ***swap()*** y ***array_is_sorted()***|
| **sort_helpers.o**  | Archivo binario con las Implementaciones las funciones declaradas en sort_helpers.h (código compilado para la arquitectura **x86-64**) |
| **sort.h**          | Prototipo de la función ***insertion_sort()*** y su descripción |
| **sort.c**          | Contiene una implementación incompleta de ***insertion_sort()***, falta implementar ***insert()*** |
| **main.c**          | Programa principal que carga un *array* de números, luego lo ordena con la función ***insertion_sort()*** y finalmente comprueba que el arreglo sea permutación ordenada del que se cargó inicialmente |

> [!WARNING]
Si se trabaja en una computadora con arquitectura distinta a **x86-64**, entonces seleccionar y
renombrar uno de los siguientes archivos, **sort_helpers.o_32** o **sort_helpers.o_macos** según la
arquitectura de su máquina.

#### Parte A: Ordenación por Inserción
Se debe realizar una implementación del algoritmo de ordenación por inserción (alias *insertion-sort*). Para
ello es necesario completar la implementación del “procedimiento” ***insert()*** en el módulo **sort.c**. 
Como guía puede examinar el resto del archivo **sort.c** y la definición del algoritmo de ordenación por
inserción vista en el teórico. El algoritmo debe ordenar con respecto a la relación ***goes_before()*** 
declarada en **sort_helpers.h** cuya implementación está oculta puesto que viene ya compilada 
en **sort_helpers.o**.

#### Parte B: Chequeo de invariante
Se debe modificar el “procedimiento” ***insertion_sort()*** agregando la verificación de cumplimiento de la
invariante del ciclo *for* que se vio en el teórico. Por simplicidad sólo se debe verificar la siguiente
parte de la invariante:

- el segmento inicial **a[0,i)** del arreglo está ordenado.

Para ello usar las funciones ***assert()*** y ***array_is_sorted()***.

Una vez implementados los incisos *a)* y *b)*, se puede compilar ejecutando:
~~~
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort.c main.c
~~~
~~~
gcc -Wall -Werror -Wextra -pedantic -std=c99 -no-pie array_helpers.o sort.o sort_helpers.o main.o -o sorter
~~~
la opción **-no-pie** tiene que ver con que se están “linkeando” los objetos **array_helpers.o**, **sort.o** y
**main.o** compilados en nuestra computadora con el objeto precompilado **sort_helpers.o**, cuya compilación fue
realizada en una computadora distinta. En consecuencia esta opción puede ser necesaria para lograr
compatibilidad entre los archivos binarios durante el “linkeo” y así poder generar el ejecutable. El programa
puede ejecutarse de la siguiente manera:
~~~
./sorter ../input/example-unsorted.in
~~~
Si el programa funciona bien en ese ejemplo(es decir, si no reporta error), probar con otros archivos de la
carpeta **../input**, sin olvidar realizar una prueba con el archivo **../input/empty.in**.

Analizar los resultados del programa y responder: ¿Qué relación implementa la función
**goes_before()**?¿Cuál es el criterio que usa?

## Ejercicio 2: Quick sort I
En este ejercicio se realizará una implementación top-down del algoritmo de ordenación rápida vista en el
teórico. En la carpeta **ej2** se encuentran los siguientes archivos:

| Archivo             | Descripción |
|---------------------|-------------|
| **array_helpers.h** | Es el mismo que en el ejercicio anterior|
| **array_helpers.c** | Es el mismo que en el ejercicio anterior|
| **sort_helpers.h**  | Contiene además la declaración y descripción de **partition()**|
| **sort_helpers.o**  | Contiene implementaciones ilegibles de esas funciones (código compilado para la arquitectura **x86-64**) |
| **sort.h**          | Contiene descripción de la función **quick_sort()**|
| **sort.c**          | Contiene una implementación muy incompleta de **quick_sort()**, además falta implementar **quick_sort_rec()**|
| **main.c**          | Programa principal que carga un *array* de números, luego lo ordena con la función **insertion_sort()** y finalmente comprueba que el arreglo sea permutación ordenada del que se cargó inicialmente |




