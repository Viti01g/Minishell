#include "../headers/minishell.h"

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
			free(view);
		}
	}
	return (EXIT_SUCCESS);
}
