#include "minishell.h"

// TODO: Manejar que me detecte los argumentos de los comandos bien
	// TODO: ejemplo: echo "hola mundo" solo tiene un arg no 2

// TODO: Manejar redirecciones y pipes dentro de las comillas
// TODO: Hacer una función que se llame double quote su funcionamiento es así:
		// * Al tokenizar si encuentra una comilla doble, va a fumarse todo hasta
		// * hasta la siguiente comilla doble y va a llamar en paralelo a double quote
		// * la cual devuelve un char * que sería el nuevo token ole ole ole


void	ft_leaks()
{
	system("leaks -q minishell");
}

int	handle_quotes(int i, char *str, char del)
{
	int	j;

	j = 0;
	if (str[i + j] == del)
	{
		j++;
		while (str[i + j] != del && str[i + j])
			j++;
		j++;
	}
	return (j);
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
//		check_quotes(input);
		si = retrieve_double_quote(input);
		free(si);
		free(input);
	}
	//system("leaks -q minishell");
	atexit(ft_leaks);
	return (0);
}
