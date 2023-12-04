#include "../headers/minishell.h"

void	ft_leaks(void)
{
	system("leaks -q minishell");
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;
	int		i;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		i = -1;
		while (tmp->str[++i])
			free(tmp->str[i]);
		free(tmp->str);
		free(tmp);
	}
}

void	process_simple_operator(char *input, t_token **tokens, int *i, int *j)
{
	char	*fragment;

	fragment = ft_substr(input, *j, *i - *j);
	ft_lstnew_addback(tokens, fragment);
	free(fragment);
}

void	process_double_operator(char *input, t_token **tokens, int *i)
{
	char	*fragment;

	fragment = ft_substr(input, *i, 2);
	ft_lstnew_addback(tokens, fragment);
	(*i)++;
	free(fragment);
}

void	process_single_operator(char *input, t_token **tokens, int *i)
{
	char	*fragment;

	fragment = ft_substr(input, *i, 1);
	ft_lstnew_addback(tokens, fragment);
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

/* void	process_tokens(char *input, t_token **tokens)
{
	int		i;
	t_token	*current_token;
	char	**current_words;
	int		token_index;
	int		word_index;

	split_token(input, tokens);
	current_token = *tokens;
	token_index = 1;
	while (current_token != NULL)
	{
		printf("\nToken %d\n", token_index);
		current_words = current_token->str;
		word_index = 1;
		i = -1;
		while (current_words[++i])
			printf("Word %d: %s\n", word_index++, current_words[i]);
		current_token = current_token->next;
		token_index++;
	}
} */

void	print_tokens(t_token **tokens)
{
	t_token	*current_token;
	char	**current_words;

	current_token = *tokens;
}

void	process_tokens(char *input, t_token **tokens)
{
	int		i;
	t_token	*current_token;
	char	**current_words;
	int		token_index;
	int		word_index;

	split_token(input, tokens);
	current_token = *tokens;
	token_index = 1;
	while (current_token != NULL)
	{
		printf("\nToken %d\n", token_index);
		current_words = current_token->str;
		word_index = 1;
		i = -1;
		while (current_words[++i])
			printf("Word %d: %s\n", word_index++, current_words[i]);
		current_token = current_token->next;
		token_index++;
	}
}

int	main(void)
{
	char	*input;
	t_token	*tokens;

	atexit(ft_leaks);
	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		printf("%p\n", input);
		if (!input)
			break ;
		process_tokens(input, &tokens);
		free(input);
		free_tokens(tokens);
		tokens = NULL;
	}
	return (0);
}
