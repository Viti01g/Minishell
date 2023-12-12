#include "minishell.h"

void	ft_leaks(void)
{
	system("leaks -q minishell");
}

void	split_token(char *input, t_token **tokens)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (input[++i])
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
	}
	if (j < i)
		process_simple_operator(input, tokens, &i, &j);
	print_tokens(tokens);
}

int	main(void)
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
}