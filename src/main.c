
#include "../headers/minishell.h"
void	view_prompt(void)
{
	write(1, GREEN, ft_strlen(GREEN));
	write(1, "minishell$ ", strlen("minishell$ "));
	write(1, RESET, ft_strlen(RESET));
}

int	main(int argc, char **argv, char **env)
{
	char		*view;
	t_general	gen;
	char		**manolo;

	manolo = argv;
	manolo = env;


	view = "a";
	if (argc != 1)
		exit(EXIT_FAILURE);
	while (1)
	{
		view = readline("\e[1;32mminishell$ \e[0m");

		if (ft_strlen(view) > 0)
		{
			add_history(view);
			gen.lineaEntera = ft_split(view, ' ');
			while (*gen.lineaEntera != NULL) {
				printf("Token: %s\n", *gen.lineaEntera);
				gen.lineaEntera++;
			}
			free(view);
		}
	}
	return (EXIT_SUCCESS);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
	char* input;

	// Bucle para leer continuamente la entrada del usuario
	while (1) {
		input = readline("MiShell> ");

		// Comprobar si el usuario ha ingresado algo
		if (strlen(input) > 0) {
			// Agregar la entrada al historial
			add_history(input);

			// Imprimir la entrada para verificar
			printf("Entrada del usuario: %s\n", input);

			// Dividir la entrada en tokens basados en espacios en blanco
			char* token = strtok(input, " ");
			while (token != NULL) {
				printf("Token: %s\n", token);
				token = strtok(NULL, " ");
			}

			// Liberar la memoria asignada a la entrada
			free(input);
		}
	}

	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para dividir una cadena en tokens basados en un delimitador
char** split(char* str, const char* delimiter, int* token_count) {
	// Variables
	char** tokens = NULL;
	char* token = strtok(str, delimiter);
	int count = 0;

	// Bucle para dividir la cadena y almacenar los tokens
	while (token != NULL) {
		count++;
		tokens = realloc(tokens, count * sizeof(char*));
		tokens[count - 1] = token;
		token = strtok(NULL, delimiter);
	}

	// Establecer el conteo de tokens y devolver el arreglo de tokens
	*token_count = count;
	return tokens;
}

int main() {
	char* input;

	while (1) {
		input = readline("MiShell> ");

		if (strlen(input) > 0) {
			// Imprimir la entrada para verificar
			printf("Entrada del usuario: %s\n", input);

			// Dividir la entrada en tokens basados en espacios en blanco
			int token_count;
			char** tokens = split(input, " ", &token_count);

			// Imprimir los tokens
			for (int i = 0; i < token_count; i++) {
				printf("Token %d: %s\n", i + 1, tokens[i]);
			}

			// Liberar la memoria asignada a la entrada y a los tokens
			free(input);
			free(tokens);
		}
	}

	return 0;
}
*/