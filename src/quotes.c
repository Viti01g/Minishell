#include "minishell.h"

/* void	ft_leaks()
{
	system("leaks -q minishell");
} */

int	process_quotes(char *str, int i, char del)
{
	int	j;

	j = i;
	i++;
	while (str[i] != del && str[i])
		i++;
	if (str[i] == del)
		i++;
	return (i - j);
}

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



int	check_quotes(char *input)
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
	if (double_flag || single_flag)
	{
		error_quote(0);
		return 0;
//		ft_error("Quotes are not closed");
	}
	return 1;
}
/* 
int	main(void)
{
	char	*input;
	char	*si;

	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		printf("%p\n", input);
		if (!input || !ft_strcmp(input, "exit"))
			break ;
//		check_quotes(input);
		si = retrieve_double_quote(input);
		free(si);
		free(input);
	}
	//system("leaks -q minishell");
	atexit(ft_leaks);
	return (0);
} */


// wqeqw"ssdff""<"