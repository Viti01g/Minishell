
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
	t_general	gen;
	//t_token *tok;
	//char		**manolo;

	(void)argv;
	gen.token = NULL;
	//gen.token = tok;
	//atexit(ft_leaks);
	ft_disable_ctrl_c_printing_chars();
	view = "a";
	init_vars(&gen, env);
	if (argc < 1)
		exit(EXIT_FAILURE);
	while (1)
	{
		ft_signals();
		view = readline("\e[1;32mminishell$ \e[0m");
		if (!view)
			break;
		split_token(view, &gen.token);
		//gen.token = tokens;
		//printf("si\n");
		if (ft_strlen(view) != 0)
		{
			gen.args = count_txt(gen.token->str);
			add_history(view);
			t_token *current = gen.token;
			while (current != NULL)
				current = current->next;
		//	printf("\n");
			ft_exec_buitins(&gen);
			//cmd_cd(gen.token->str);
			free_tokens(gen.token);
			gen.token = gen.token->next;
		}
		free(view);
		gen.token = NULL;
		//tcsetattr(0, 0, &inf.termios);
	}
	return (EXIT_SUCCESS);
} */
