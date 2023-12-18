#include "minishell.h"

// TODO: Manejar que me detecte los argumentos de los comandos bien
	// TODO: ejemplo: echo "hola mundo" solo tiene un arg no 2

int	change_quote_state(int quote)
{
	if (quote == FALSE)
		return (TRUE);
	else
		return (FALSE);
}

void	until_double(char *input, int *i, int *double_flag)
{
	if (input[*i] == '\"')
	{
		*double_flag = change_quote_state(*double_flag);
		(*i)++;
		while (input[*i] != '\"' && input[*i])
			(*i)++;
		if (input[*i] == '\"')
			*double_flag = change_quote_state(*double_flag);
	}
}

void	until_single(char *input, int *i, int *single_flag)
{
	if (input[*i] == '\'')
	{
		*single_flag = change_quote_state(*single_flag);
		(*i)++;
		while (input[*i] != '\'' && input[*i])
			(*i)++;
		if (input[*i] == '\'')
			*single_flag = change_quote_state(*single_flag);
	}
}

void	check_quotes(char *input)
{
	int	double_flag;
	int	single_flag;
	int	i;

	i = -1;
	double_flag = FALSE;
	single_flag = FALSE;
	while (input[++i])
	{
		until_double(input, &i, &double_flag);
		until_single(input, &i, &single_flag);
	}
	if (double_flag == FALSE)
		printf("Comillas dobles cerradas o no hay\n");
	if (double_flag == TRUE)
		printf("Comillas dobles abiertas\n");
	if (single_flag == FALSE)
		printf("Comillas simples cerradas o no hay\n");
	if (single_flag == TRUE)
		printf("Comillas simples abiertas\n");
}

int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		printf("%p\n", input);
		if (!input || !ft_strcmp(input, "exit"))
			break ;
		check_quotes(input);
		free(input);
	}
	return (0);
}
