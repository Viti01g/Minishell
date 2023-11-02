#include "../headers/minishell.h"

/* int	main(int argc, char **argv, char **env)
{
	char		*view;
	t_general	gen;
	char		**manolo;
	int			i;

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

			i = -1;
			add_history(view);
			gen.linea_entera = ft_split(view, ' ');
			while (gen.linea_entera[i++])
				printf("Token: %s  tipo: %d\n", gen.linea_entera[i], -7);
			free(view);
		}
	}
	return (EXIT_SUCCESS);
} */

/* int	main(int argc, char **argv, char **env)
{
	char		*view;
	t_general	gen;
	char		**manolo;
	int			i;
	int			j;
	char		*command;

	manolo = argv;
	manolo = env;


	command = NULL;
	gen.linea_entera = NULL;

	view = NULL;
	if (argc != 1)
		exit(EXIT_FAILURE);
	while (1)
	{
		view = readline("\e[1;32mminishell$ \e[0m");
		if (!view)
			break ;
		if (ft_strlen(view) > 0)
		{
		
			i = 0;
			add_history(view);
			while (view[i])
			{
				j = i;
				while ((view[i] != '|' && view[i] != '<' && view[i] != '>') && view[i])
					j++;
				command = ft_substr(view, i, j - i);
				printf("Token: %s\n", command);
				if (view[j])
					i = j + 1;
				else
					break ;
				//i++;
			}
			// gen.linea_entera = ft_split(view, ' ');
			// while (gen.linea_entera[i++])
			// 	printf("Token: %s  tipo: %d\n", gen.linea_entera[i], -7);
		}
		free(view);
	}
	return (EXIT_SUCCESS);
} */

int	main(void) 
{
    char *input;
    char *fragment;
    int operator_found;
	int	i;
	int j;

	operator_found = 0;
	i = 0;
    while (1) 
	{
        input = readline("\e[1;32mminishell$ \e[0m");
        if (!input) 
            break;
		j = i;
		while (input[i])
		{
		if (input[i] == '|' || input[i] == '<' || input[i] == '>' || input[i + 1] == '\0')
		{
			operator_found = 1;
			//if (input[i + 1] == '\0')
			//-j = i + 1;
			fragment = ft_substr(input, j, i - j);
			printf("Operador encontrado: %s\n", fragment);
		}
		i++;
		printf("Valor de %d\n", i);
		}
        if (operator_found) {
            //printf("Operador encontrado('%c'): %s\n", input[i], fragment);
            free(fragment); // No olvides liberar la memoria asignada
            operator_found = 0;
        }
   //     free(input); // Liberar la memoria asignada por readline
    }
    return 0;
}


/* void	classify_value(char **tokens)
{
	int i = 0;
	
} */


/*
	TODO: Todo texto plano va a ser un comando
	TODO: Se va a separar todo por operadores
	TODO: Clasificar el resto de operadores // ! Dejar para el final la doble flecha
	TODO: Usar funciones del pipex
	*Todas Mienten, que no se te olvide.
*/