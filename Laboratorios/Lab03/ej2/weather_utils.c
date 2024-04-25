#include "array_helpers.h"
#include <limits.h>
int minima_temp(WeatherTable array)
{
    int min = INT_MAX;
    for (unsigned int year = 0u; year < YEARS; ++year)
    {
        for (month_t month = january; month <= december; ++month)
        {
            for (unsigned int day = 0u; day < DAYS; ++day)
            {
                if (min > array[year][month][day]._min_temp)
                {
                    min = array[year][month][day]._min_temp;
                }
            }
        }
    }
    return min;
}

void temp_maximas(WeatherTable array, int maximas[YEARS])
{
    int max = INT_MIN;
    for (unsigned int year = 0u; year < YEARS; ++year)
    {
         max = INT_MIN;
        for (month_t month = january; month <= december; ++month)
        {
            for (unsigned int day = 0u; day < DAYS; ++day)
            {
                if (max < array[year][month][day]._max_temp)
                {
                    max = array[year][month][day]._max_temp;
                }
            }
        }
        maximas[year] = max;
    }
}

void precipitaciones(WeatherTable array, month_t output[YEARS])
{
    int max, sum_mes;

    for (unsigned int year = 0u; year < YEARS; ++year)
    {
        max = INT_MIN;
        for (month_t month = january; month <= december; ++month)
        {
            sum_mes = 0;
            for (unsigned int day = 0u; day < DAYS; ++day)
            {
                sum_mes = sum_mes + array[year][month][day]._rainfall;
            }
            if (sum_mes > max)
            {
                max = sum_mes;
                output[year] = month;
            }
        }
    }
}
void dump(int a[], unsigned int length)
{
    if (length == 0)
    {
        printf("[]\n");
    }
    else
    {

        printf("[");
        for (size_t i = 0; i < length - 1; i++)
        {
            printf("%d,", a[i]);
        }
        printf("%d]\n\n", a[length - 1]);
    }
}

char* month_to_string(month_t month) { 
    switch (month) {
        case january:   return "January";
        case february:  return "February";
        case march:     return "March";
        case april:     return "April";
        case may:       return "May";
        case june:      return "June";
        case july:      return "July";
        case august:    return "August";
        case september: return "September";
        case october:   return "October";
        case november:  return "November";
        case december:  return "December";
        default:        return "Unknown";
    }
}

void array_dump_month(month_t array[YEARS])
{
    printf("[");
    for (unsigned int year = 0; year < YEARS - 1; year++)
    {
        printf("%s, ", month_to_string(array[year]));
    }
    printf("%s]\n\n", month_to_string(array[YEARS-1]));
}