#include <unistd.h>
#include <stdio.h>
#include "minishell.h"

#define TRUE  1
#define FALSE  0


void check_quotes(char *input)
{
	int	i;
	int	double_flag;
	int	single_flag;

	i = 0;
	double_flag = FALSE;
	single_flag = FALSE;
	if (input[i] == '\"')
	{
		double_flag = TRUE;
		while (input[i] != '\"' && input[i] != '\0')
		{
			printf("hola\n");
			i++;
		}
		if (input[i] == '\"')
			double_flag = FALSE;
	}
	else if (input[i] == '\'')
	{
		single_flag = TRUE;
		while (input[i] != '\'' && input[i])
			i++;
		if (input[i] == '\'')
			single_flag = FALSE;
	}
	if (double_flag == FALSE)
		printf("Comillas dobles cerradas o no hay\n");
	else if (double_flag == TRUE)
		printf("Comillas dobles abiertas\n");
	else if (single_flag == FALSE)
		printf("Comillas simples cerradas o no hay\n");
	else if (single_flag == TRUE)
		printf("Comillas simples abiertas\n");
}

int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		printf("%p\n", input);
		// TODO: Cambiar el strncmp por un strcmp
		if (!input || !ft_strncmp(input, "exit", 4))
			break ;
		check_quotes(input);
		free(input);
	}
	return (0);
}
