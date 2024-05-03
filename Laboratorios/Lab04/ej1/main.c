/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void) {
    int x = 1;
    int a[] = {0, 1, 2, 3};
    person_t m = {90, 'M'};

    int *p = NULL; 
    p = &x;
    *p = 9;

    p = &a[1];
    *p = 42;

    person_t *f = NULL;
    f = &m;
    f->age = 100;
    (*f).name_initial = 'F'; // Otra forma de escribirlo.

    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}

