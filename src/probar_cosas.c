//# include "minishell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* int main(int argc, char **argv, char **envp) {
    // Tamaño del buffer para almacenar el directorio actual
    size_t buffer_size = 1024;
    char    *str[] = {"/usr/bin/wc", "-l", "-w", "caca.txt", NULL};

    str[0] = strdup("/usr/bin/wc");
    str[1] = strdup("-l");
    str[2] = strdup("-w");
    str[2] = strdup("caca.txt");
    str[3] = "\0";
 

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
/
    if (access(str[0], F_OK))
        printf("funciona\n");
    execve(str[0], str, NULL);
    return EXIT_SUCCESS;
 }*/
