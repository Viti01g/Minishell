#include "minishell.h"

// TODO: Manejar que me detecte los argumentos de los comandos bien
	// TODO: ejemplo: echo "hola mundo" solo tiene un arg no 2

// TODO: Manejar redirecciones y pipes dentro de las comillas
// TODO: Hacer una función que se llame double quote su funcionamiento es así:
		// * Al tokenizar si encuentra una comilla doble, va a fumarse todo hasta
		// * hasta la siguiente comilla doble y va a llamar en paralelo a double quote
		// * la cual devuelve un char * que sería el nuevo token ole ole ole


void ft_leaks()
{
	system("leaks -q minishell");
}

/* void	select_quote_mode(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{

		i++;
	}
} */

/* char	*retrieve_double_quote(char *input)
{
	int		i;
	int		start;
	int		stop;
	char	*token;

	i = -1;
	start = 0;
	stop = 0;
	while (input[++i])
	{
		if (input[i] == '\"')
		{
			start = i;
			i++;
			while (input[i] != '\"')
				i++;
			stop = i;
			printf("Esto vale start: %d\n", start);
			printf("Esto vale stop: %d\n", stop);
			break ;
		}
	}
	token = ft_substr(input, start + 1, (stop - start) - 1);
	printf("Este es tu token mi rey: %s\n", token);
	return (token);
} */

char	*retrieve_double_quote(char *input)
{
	int		i;
	int		start;
	int		stop;
	int		in_quotes;
	char	*token;

	i = -1;
	start = 0;
	stop = 0;
	while (input[++i])
	{
		if (input[i] == '\"')
		{
			start = i;
			while (start > 0 && input[start - 1] != ' ' && input[start - 1] != '\t')
				start--;
			in_quotes = 1;
		}
		else
		{
			stop = i;
			in_quotes = 0;
			printf("esta es la len de ft_strlen de input: %d\n", ft_strlen(input));
			printf("y este es su último char: %c\n", input[ft_strlen(input) - 1]);
			while (stop < ft_strlen(input) && input[stop + 1] != ' ' && input[stop + 1] != '\t')
				stop++;
			printf("Esto vale stop: %d\n", stop);
			printf("Y es este char: %c\n", input[stop - 1]);
			break ;
		}
	}
	token = ft_substr(input, start, (stop - start));
	printf("Este es tu token mi rey: %s\n", token);
	return (token);
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
}

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
	//	check_quotes(input);
		si = retrieve_double_quote(input);
		free(si);
		free(input);
	}
	//system("leaks -q minishell");
	atexit(ft_leaks);
	return (0);
}
