#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int list_elem;

typedef struct node_* list;

/* Constructores */

list empty_list(void);
// Crea una lista vacía.

list addl_list(list l, list_elem e);
// Agrega el elemento e por izquierda a la lista l.


/* Destructor */

list destroy_list(list l);
// Libera memoria en caso de ser necesario.


/* Operaciones */

bool is_empty_list(list l);
// Devuelve true si la list l es vacia.

list_elem head_list(list l);
// Devuelve el primer elemento de la lista l.
// PRE: La lista no es vacia --> !is_empty(l). 

list tail_list(list l);
// Elimina el primer elemento de la lista l.
// PRE: La lista no es vacia --> !is_empty(l).

list addr_list(list l, list_elem e);
// Agrega el elemento e al final de la lista l.

unsigned int length_list(list l);
// Devuelve la cantidad de elementos de l.

list concat_list(list l, list lx);
// Agrega al final de l todos los elementos de lx en el mismo orden.

list_elem index_list(list l, unsigned int n);
// Devuelve el n-esimo elemento de la lista l.
// PRE: El largo de la lista es mayor que n --> length_list(l) > n.

list take_list(list l, unsigned int n);
// Deja en l solo los primeros n elementos, eliminando el resto.

list drop_list(list l, unsigned int n);
// Elimina los primeros n elementos de l.

list copy_list(list l);
// Devuelve una copia de la lista l.