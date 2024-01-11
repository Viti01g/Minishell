
#include "minishell.h"

void	ft_error(char *error)
{
	printf("\033[1;31mError: %s\033[0m\n", error);
	exit(EXIT_FAILURE);
}

void	view_prompt(void)
{
	write(1, GREEN, ft_strlen(GREEN));
	write(1, "minishell$ ", strlen("minishell$ "));
	write(1, RESET, ft_strlen(RESET));
}


// TODO: Cambiar el strncmp por un strcmp
/* int	main(int argc, char **argv, char **env)
{
	char		*view;
	t_token		*tokens;
	char		**manolo;

	manolo = argv;
	manolo = env;

	atexit(ft_leaks);

	ft_disable_ctrl_c_printing_chars();
	view = "a";
	if (argc != 1)
		exit(EXIT_FAILURE);
	
	while (1)
	{
		ft_signals();
		view = readline("\e[1;32mminishell$ \e[0m");
		if (!view)
			break;
		split_token(view, &tokens);
		g_gen.token = tokens;
		if (ft_strlen(view) != 0)
		{
			add_history(view);
			t_token *current = tokens;
			while (current != NULL)
			{
				for (int i = 0; current->str[i] != NULL; i++)
					printf("%s ", current->str[i]);
				//printf("\n");
				current = current->next;
			}
			printf("esto: %s\n", tokens->str[1]);
			cmd_cd(tokens->str);
			free_tokens(tokens);
			free(view);
		}
			tokens = tokens->next;
		tcsetattr(0, 0, &g_info.termios);
	}
	return (EXIT_SUCCESS);
} */
