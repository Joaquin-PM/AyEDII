#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

void print_help(char *program_name)
{
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[])
{
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count)
    {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int data_from_file(const char *path, 
                                unsigned int indexes[], 
                                char letters[], 
                                unsigned int max_size){
    FILE *file;

    unsigned int i = 0u;

    file = fopen(path, "r");

    if (file == NULL)
    {
        printf("Error al cargar el archivo.\n");
        exit(EXIT_FAILURE);
    }

    while (!feof(file) && i <= max_size)
    {
        fscanf(file, "%u -> *%c*\n", &indexes[i], &letters[i]);
        i++;
    }
    fclose(file);
    return i;
}

int main(int argc, char *argv[]) {
    const char *file;
    file = parse_filepath(argc, argv);

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length;
    
    length = data_from_file(file, indexes, letters, MAX_SIZE);

    for (size_t i = 0; i < length; i++)
    {
        sorted[i] = letters[indexes[i]];   
    }

    dump(sorted, length);

    return EXIT_SUCCESS;
}
//

