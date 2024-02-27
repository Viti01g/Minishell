
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


/* int main(int argc, char **argv, char **env)
{
	char		*view;
	t_general	gen;

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
		view = ft_strtrim(view, " \n\t\r\v\f");
		check_quotes(view);
		gen.num_pipes = split_token(view, &gen.token);
		if (ft_strlen(view) != 0)
		{
			gen.args = count_txt(gen.token->str);
			add_history(view);
			t_token *current = gen.token;
			while (current != NULL)
				current = current->next;
			exec(&gen);
			ft_exec_builtins(&gen);
			free_tokens(gen.token);
			gen.token = gen.token->next;
		}
		free(view);
		gen.token = NULL;
	//	atexit(ft_leaks);
	}
	return (EXIT_SUCCESS); 
} */


/* int	main(int argc, char **argv, char **env)
{
	char		*input;
	t_general	gen;

	(void)argv;
	(void)argc;
//  atexit(ft_leaks);
	gen.token = NULL;
	init_vars(&gen, env);
	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		if (!input || !ft_strcmp(input, "exit"))
			break ;
		check_quotes(input);
		input = expander(input);
		split_token(input, &gen.token);
		ft_exec_builtins(&gen);
		free(input);
		free_tokens(gen.token);
		gen.token = NULL;
	}
	return (0);
} */

int	main(int argc, char **argv, char **env)
{
	char		*input;
	t_general	gen;

	(void)argv;
	(void)argc;
//  atexit(ft_leaks);
	gen.token = NULL;
	init_vars(&gen, env);
	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		if (!input || !ft_strcmp(input, "exit"))
			break ;
		check_quotes(input);
		input = expander(input);
		split_token(input, &gen.token);
		//*****************************************************************
		//* Añadidas para probar lo de eliminar comillas, luego se unifica
		//* Recuerda que print_tokens está comentada en split_token
		remove_quotes_from_tokens(gen.token);
		print_tokens(&gen.token);
		//*****************************************************************
		//ft_exec_builtins(&gen);
		free(input);
		free_tokens(gen.token);
		gen.token = NULL;
	}
	return (0);
}

int	cont_pipes(t_token **token)
{
	t_token	*aux;
	int		i;
	aux = *token;

	i = 0;
	while(aux != NULL)
	{
		if (aux->type == PIPE)
			i++;
		aux = aux->next;
	}
	return (i);
}