# include "headers/minishell.h"

void	view_prompt(void)
{
	write(1, GREEN, ft_strlen(GREEN));
	write(1, "minishell$ ", strlen("minishell$ "));
	write(1, RESET, ft_strlen(RESET));
}

int	main(int argc, char **argv)
{
	char *view;

	view = "a";
	if (argc != 1)
		exit(EXIT_FAILURE);
	while (1)
	{
		// view_prompt();
		view = readline("\e[1;32mminishell$ \e[0m");
	}
	return (EXIT_SUCCESS);
}
