#include "minishell.h"

// TODO: Manejar que me detecte los argumentos de los comandos bien
	// TODO: ejemplo: echo "hola mundo" solo tiene un arg no 2

// TODO: Manejar redirecciones y pipes dentro de las comillas
// TODO: Hacer una función que se llame double quote su funcionamiento es así:
		// * Al tokenizar si encuentra una comilla doble, va a fumarse todo hasta
		// * hasta la siguiente comilla doble y va a llamar en paralelo a double quote
		// * la cual devuelve un char * que sería el nuevo token ole ole ole


/* void	ft_leaks()
{
	system("leaks -q minishell");
} */

int	is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

int	skip_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (is_whitespace(str[i + j]))
		j++;
	return (j);
}

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
	printf("Valor de comillas dobles: %d\n", double_flag);
	printf("Valor de comillas simples: %d\n", single_flag);
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
