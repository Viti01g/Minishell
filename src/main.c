
#include "minishell.h"

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
	//char		**manolo;

	(void)argv;

	//atexit(ft_leaks);
	ft_disable_ctrl_c_printing_chars();
	view = "a";
	if (argc != 1)
		exit(EXIT_FAILURE);
	while (1)
	{
		ft_signals();
		view = readline("\e[1;32mminishell$ \e[0m");
		init_vars(&gen, env);
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
}

/* int	main(void)
{
	char	*input;
	t_token	*tokens;

	atexit(ft_leaks);
	tokens = NULL;
	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		printf("%p\n", input);
		if (!input || !ft_strncmp(input, "exit", 4))
			break ;
		split_token(input, &tokens);
		free(input);
		free_tokens(tokens);
		tokens = NULL;
	}
	return (0);
} */