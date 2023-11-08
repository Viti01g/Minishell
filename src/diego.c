#include "../headers/minishell.h"

/* int	main(int argc, char **argv, char **env)
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
			int i = -1;
			add_history(view);
			gen.linea_entera = ft_split(view, ' ');
			while (gen.linea_entera[i++])
				printf("Token: %s  tipo: %d\n", gen.linea_entera[i], -7);
			free(view);
		}
	}
	return (EXIT_SUCCESS);
} */
/* 
void	classify_value(char **tokens)
{
	int i = 0;
	
} */


/*
	TODO: Todo texto plano va a ser un comando
	TODO: Clasificar el resto de operadores // ! Dejar para el final la doble flecha
	TODO: Usar funciones del pipex
	*Todas Mienten, que no se te olvide.
*/