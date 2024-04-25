#ifndef WEATHER_UTILS_H
#define WEATHER_UTILS_H

int minima_temp(WeatherTable array);

void temp_maximas(WeatherTable array, int maximas[YEARS]);

void precipitaciones(WeatherTable array, month_t output[YEARS]);

void dump(int a[], unsigned int length);

void array_dump_month(month_t array[]);



#endif