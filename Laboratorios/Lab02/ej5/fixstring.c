#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s)
{
    unsigned int i = 0;
    while (s[i] != '\0' && i < FIXSTRING_MAX)
    {
        i++;
    }
    return i;
}

bool fstring_eq(fixstring s1, fixstring s2)
{
    bool eq = true;

    if (fstring_length(s1) == fstring_length(s2))
    {
        for (unsigned int i = 0; i < fstring_length(s1); i++)
        {
            eq = s1[i] == s2[i] && eq;
        }
    }
    else
    {
        eq = false;
    }

    return eq;
}

bool fstring_less_eq(fixstring s1, fixstring s2)
{
    bool less_eq;
    unsigned int i = 0;

    while (s1[i] == s2[i] && i < FIXSTRING_MAX)
    {
        i++;
    };
    less_eq = s1[i] <= s2[i];

    return less_eq;
}

void fstring_set(fixstring s1, const fixstring s2)
{
    int i = 0;
    while (i < FIXSTRING_MAX && s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1, fixstring s2)
{
    fixstring aux;

    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}
