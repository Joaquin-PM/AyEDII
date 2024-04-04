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
