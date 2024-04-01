#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data
{
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length)
{
    struct bound_data res;

    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;

    for (size_t i = 0; i < length; i++)
    {
        res.is_upperbound = res.is_upperbound && value >= arr[i];
        res.is_lowerbound = res.is_lowerbound && value <= arr[i];
        res.exists = res.exists || arr[i] == value;

        if (arr[i] == value)
        {
            res.where = i;
        }
    }

    return res;
}

int main(void)
{
    struct bound_data result;
    int a[ARRAY_SIZE];
    int value;

    // Pide un valor para value
    printf("Introduce un valor entero\n");
    scanf("%d", &value);

    // Pide los valores del arreglo.
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Ingrese un valor para la posicion %lu del arreglo\n", i);
        scanf("%d", &a[i]);
    }

    result = check_bound(value, a, ARRAY_SIZE);

    printf("%d\n", result.is_upperbound);
    printf("%d\n", result.is_lowerbound);
    printf("%u\n", result.exists);
    if (result.exists)
    {
        printf("%u\n", result.where);
    }

    return EXIT_SUCCESS;
}
