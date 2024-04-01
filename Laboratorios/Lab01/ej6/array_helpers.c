#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath)
{
    FILE *archivo = fopen(filepath, "r");

    if (archivo == NULL)
    {
        fprintf(stderr, "Error: no se pudo abrir el archivo %s\n", filepath);
        exit(EXIT_FAILURE);
    }

    int elemArray;
    unsigned int cantPos;
    fscanf(archivo, "%u", &cantPos);

    if (cantPos <= max_size)
    {
        for (unsigned int i = 0; i < cantPos; i++)
        {
            if (fscanf(archivo, "%d", &elemArray) != EOF)
            {
                array[i] = elemArray;
            }
            else
            {
                printf("Formato invalido\n");
                fclose(archivo);
                exit(EXIT_FAILURE);
            }
        }
    }
    else
    {
        fprintf(stderr, "La longitud del arreglo en %s exede el màximo permitido\n", filepath);
        fclose(archivo);
        exit(EXIT_FAILURE);
    }

    fclose(archivo);

    return cantPos;
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

bool array_is_sorted(int a[], unsigned int length)
{
    bool orden = true;

    for (size_t i = 0; i < length - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            orden = false;
        }
        i++;
    }
    return orden;
}

void array_swap(int a[], unsigned int i, unsigned int j)
{
    int auxiliar = a[i];
    a[i] = a[j];
    a[j] = auxiliar;
}