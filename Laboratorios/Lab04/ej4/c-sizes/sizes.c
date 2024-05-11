#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int 
main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n",
           sizeof(messi.name), sizeof(messi.age), 
           sizeof(messi.height), sizeof(data_t));
   
    printf("name-memory  : %p\n"
           "age-memory   : %p\n"
           "height-memory: %p\n"
           "data_t-memory: %p\n",
           (void *)&messi.name, (void *)&messi.age, 
           (void *)&messi.height, (void *)&messi);

    return EXIT_SUCCESS;
}

