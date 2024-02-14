
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

// TODO: Meter el skip_spaces de las comillas para no tokenizar los espacios ni tabulaciones
/* int	main(int argc, char **argv, char **env)
{
	char		*view;
	t_general	gen;
	//t_token		*tokens;
	//char		**manolo;

	(void)argv;
	gen.token = NULL;
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
		check_quotes(view);
		split_token(view, &gen.token);
		if (ft_strlen(view) != 0)
		{
			gen.args = count_txt(gen.token->str);
			add_history(view);
			t_token *current = gen.token;
			while (current != NULL)
				current = current->next;
			ft_exec_builtins(&gen);
			free_tokens(gen.token);
			gen.token = gen.token->next;
		}
		free(view);
		gen.token = NULL;
	//	atexit(ft_leaks);
		//tcsetattr(0, 0, &inf.termios);
	}
	return (EXIT_SUCCESS); 
} */

int	main(int argc, char **argv, char **env)
{
	char	*input;
//	t_token	*tokens;
	t_general gen;
	(void)argc;
	(void)argv;

	//atexit(ft_leaks);
//	tokens = NULL;
//	printf("%p\n", input);
//	printf("%s\n", input);
	init_vars(&gen, env);
	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		if (!input || !ft_strcmp(input, "exit"))
			break ;
		//check_quotes(input);
		//split_token(input, &tokens);
		input = expander(input);
		printf("Esto es lo que le llega a print %s\n", input);
		print_env_var(&gen, input);
		printf("Este es tu input:\n %s\n", input);
		free(input);
	//	free_tokens(tokens);
	//	tokens = NULL;
	}
	atexit(ft_leaks);
	return (0);
}