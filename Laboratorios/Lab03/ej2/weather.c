/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

static const int AMOUNT_OF_WEATHER_VARS = 6;

Weather weather_from_file(FILE *file)
{
  Weather weather;
  int verif;
  
   verif =fscanf(file, EXPECTED_WEATHER_FILE_FORMAT, &weather._average_temp, &weather._max_temp, &weather._min_temp, &weather._pressure, &weather._moisture, &weather._rainfall);
  /*Verifica que los datos esten bien leidos, caso contrario terminara el programa*/
  if (verif != AMOUNT_OF_WEATHER_VARS)
  {
    fprintf(stderr, "Error al leer los datos del archivo\n");
    fclose(file);
    exit(EXIT_FAILURE);

  }
  
  return weather;
}

void weather_to_file(FILE *file, Weather weather)
{
  fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp,
          weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}