#include "../headers/minishell.h"

/* void	ft_leaks(void)
{
	system("leaks -q minishell");
} */

/* void free_tokens(t_token *tokens)
{
	t_token *tmp;

	while (tokens) {
		tmp = tokens;
		tokens = tokens->next;
		tmp->str = NULL;
		free(tmp);
	}
} */
void	free_tokens(t_token *tokens)
{
	int		i;
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		// Liberar la doble matriz
		i = -1;
		while (tmp->str[++i])
			free(tmp->str[i]);
/* 		for (int i = 0; tmp->str[i] != NULL; i++)
		{
			free(tmp->str[i]);
		} */
		free(tmp->str);
		free(tmp);
	}
}

void	process_simple_operator(char *input, t_token **tokens, int *i, int *j)
{
	char	*fragment;

	fragment = ft_substr(input, *j, *i - *j);
	ft_lstnew_addback(tokens, fragment);
	//printf("%s\n", (*tokens)->str);
	free(fragment);
}

void	process_double_operator(char *input, t_token **tokens, int *i)
{
	char	*fragment;

	fragment = ft_substr(input, *i, 2);
	ft_lstnew_addback(tokens, fragment);
//	if ((*tokens)->next != NULL)
		//printf("%s\n", (*tokens)->next->str);
	(*i)++;
	free(fragment);
}

void	process_single_operator(char *input, t_token **tokens, int *i)
{
	char	*fragment;

	fragment = ft_substr(input, *i, 1);
	ft_lstnew_addback(tokens, fragment);
	//if ((*tokens)->next != NULL)
	//	printf("%s\n", (*tokens)->next->str);
	free(fragment);
}

void	split_token(char *input, t_token **tokens)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
		{
			process_simple_operator(input, tokens, &i, &j);
			if ((input[i] == '>' || input[i] == '<')
				&& (input[i] == input[i + 1]))
				process_double_operator(input, tokens, &i);
			else
				process_single_operator(input, tokens, &i);
			j = i + 1;
		}
		i++;
	}
	if (j < i)
		process_simple_operator(input, tokens, &i, &j);
}
/* 
int	main(void)
{
	char	*input;
	t_token	*tokens;

	tokens = NULL;
	atexit(ft_leaks);
	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		printf("%p\n", input);
		if (!input)
			break ;
		split_token(input, &tokens);
		free(input);
		t_token *current = tokens;
		while (current != NULL)
		{
			for (int i = 0; current->str[i] != NULL; i++)
				printf("%s ", current->str[i]);
			printf("\n");
			current = current->next;
		}
		free_tokens(tokens);
		tokens = NULL;
	}
	return (0);
} */
