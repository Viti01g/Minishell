# include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Tamaño del buffer para almacenar el directorio actual
    size_t buffer_size = 1024;

    // Buffer para almacenar el directorio actual
    char *current_directory = (char *)malloc(buffer_size);
    if (current_directory == NULL) {
        perror("Error al asignar memoria para el directorio actual");
        exit(EXIT_FAILURE);
    }

    // Obtener el directorio actual
    if (getcwd(current_directory, buffer_size) != NULL) {
        printf("Directorio actual: %s\n", current_directory);
    } else {
        perror("Error al obtener el directorio actual");
        exit(EXIT_FAILURE);
    }

    // Liberar la memoria asignada al buffer
    free(current_directory);

    return EXIT_SUCCESS;
}
