### **¿Por qué en la compilación con gcc no se le pasa array_helpers.h como parámetro?**
Los **archivos.h** son de encabezado, solo tienen el prototipo de funciones y la declaracion de variables y constantes 
que luego se importan al **archivo.c** que la este llamando a traves de **#include**. Por lo tanto todo lo declarado en
el **archivo.h** se compilara luego en la compilacion del **archivo.c** que la este llamando.

### ¿Por qué falla la compilación?, ¿Como se resuelve el problema?
Falla porque se generan ***redeclaraciones*** al compilar distintos archivos que llaman a un mismo **archivo.h**,
este problema se resuelve usando la directiva de preprocesador **#ifndef** y **#endif** que funciona
algo asi como un **if()** que detecta que un **archivo.h** ya fue llamado antes entonces no lo vuelve a llamar.
