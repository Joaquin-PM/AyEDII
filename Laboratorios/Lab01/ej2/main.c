#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000 // Tamaño máximo de arreglo permitido.

unsigned int array_from_stdin(int array[], unsigned int max_size)
{
    unsigned int tamArray;
    printf("Ingrese el tamaño del arreglo\n");
    fscanf(stdin, "%u", &tamArray);

    if (tamArray > max_size)
    {
        fprintf(stderr, "Longitud no permitida\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < tamArray; i++)
    {
        printf("Ingrese el elemento de la posicion %d\n", i);
        fscanf(stdin, "%d", &array[i]);
    }

    return tamArray;
}

void array_dump(int a[], unsigned int length)
{
    if (length == 0u)
    {
        printf("No tiene valores\n");
    }
    else
    {
        printf("[ ");
        for (unsigned int i = 0u; i < length; i++)
        {
            printf("%d", a[i]);
            if (i < length - 1)
            {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

int main()
{
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_stdin(array, MAX_SIZE);

    /* dumping the array */
    array_dump(array, length);

    return EXIT_SUCCESS;
}
