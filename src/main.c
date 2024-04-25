
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

/* void categorize_arguments(t_token *tokens)
{
	t_token *current_node;

	current_node = tokens;
	while (current_node != NULL)
	{
		if (strcmp(current_node->str[0], ">") == 0 || strcmp(current_node->str[0], ">>") == 0)
		{
			current_node = current_node->next;
			if (current_node == NULL)
			{
				printf("Syntax error\n");
				return ;
			}
			if (is_command(current_node->str[0]) || access(current_node->str[0], X_OK) == 0) // Check if the file is a command
				current_node->type = CMD;
			else
				current_node->type = OUTFILE;
		}
		else if (strcmp(current_node->str[0], "<") == 0)
		{
			current_node = current_node->next;
			if (current_node == NULL)
			{
				printf("Syntax error\n");
				return ;
			}
			if (is_command(current_node->str[0]) || access(current_node->str[0], X_OK) == 0) // Check if the file is a command
				current_node->type = CMD;
			else
				current_node->type = INFILE;
		}
		current_node = current_node->next;
	}
} */


int main(int argc, char **argv, char **env)
{
	char		*view;
	t_general	gen;

	(void)argv;
	gen.token = NULL;
	gen.infile = NULL;
	gen.delim = NULL;
//	atexit(ft_leaks);
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
		view = expander(view);
		gen.num_pipes = split_token(view, &gen.token);
		remove_quotes_from_tokens(gen.token);
		categorize_arguments(gen.token);
		if (ft_strlen(view) != 0)
		{
			gen.args = count_txt(gen.token->str);
			add_history(view);
			t_token *current = gen.token;
			while (current != NULL)
				current = current->next;
			print_tokens(&gen.token);
		//	exec(&gen);
			ft_free_tokens(gen.token);	// Da seg_fault
			gen.token = gen.token->next;
		}

		free(view);
		gen.token = NULL;
	}
	return (EXIT_SUCCESS); 
}

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

int	cont_pipes(t_token **token)
{
	t_token	*aux;
	int		i;

	aux = *token;
	i = 0;
	while (aux != NULL)
	{
		if (aux->type == PIPE)
			i++;
		aux = aux->next;
	}
	return (i);
}
