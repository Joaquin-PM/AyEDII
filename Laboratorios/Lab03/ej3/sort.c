/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y)
{
    bool result = x.rank <= y.rank;
    return result;
}

bool array_is_sorted(player_t atp[], unsigned int length)
{
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i]))
    {
        i++;
    }
    return (i == length);
}
static void fstring_set(char s1[], const char s2[]) {
    unsigned int i=0;
    while (i<MAX_NAME_LENGTH + 1u && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

static void swap(player_t a[], unsigned int i, unsigned int j)
{
    player_t temp;
    fstring_set(temp.name, a[i].name); 
    fstring_set(temp.country, a[i].country);
    temp.rank = a[i].rank;
    temp.age = a[i].age;
    temp.points = a[i].points;
    temp.tournaments = a[i].tournaments;

    fstring_set( a[i].name, a[j].name); 
    fstring_set(a[i].country, a[j].country);
    a[i].rank = a[j].rank;
    a[i].age = a[j].age;
    a[i].points = a[j].points;
    a[i].tournaments = a[j].tournaments;

    fstring_set(a[j].name, temp.name); 
    fstring_set(a[j].country, temp.country); 
    
    a[j].rank = temp.rank;
    a[j].age = temp.age;
    a[j].points = temp.points;
    a[j].tournaments = temp.tournaments;
}

static unsigned int partition(player_t a[], unsigned int izq, unsigned int der)
{
    unsigned int piv = izq;
    unsigned int i, j;

    i = izq + 1;
    j = der;

    while (i <= j)
    {
        if (goes_before(a[i], a[piv]))
        {
            i++;
        }
        else if (goes_before(a[piv], a[j]))
        {
            j = j - 1;
        }
        else if (goes_before(a[piv], a[i]) && goes_before(a[j], a[piv]))
        {
            swap(a, i, j);
        }
    }
    swap(a, piv, j);
    piv = j;
    return piv;
}

/*porque con 3 if por seprado no funciona?*/

static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der)
{
    unsigned int piv;
    if (der > izq)
    {
        piv = partition(a, izq, der);
        quick_sort_rec(a, izq, (piv == 0u) ? 0u : piv - 1u);
        quick_sort_rec(a, piv + 1, der);
    }
}

void sort(player_t a[], unsigned int length)
{
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}