#include "minishell.h"

/* void check_quotes(char *input)
{
	int	i;
	int	double_flag;
	int	single_flag;

	i = 0;
	double_flag = FALSE;
	single_flag = FALSE;
	while (input[i])
	{
		if (input[i] == '\"')
		{
			i++;
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
			i++;
			single_flag = TRUE;
			while (input[i] != '\'' && input[i])
				i++;
			if (input[i] == '\'')
				single_flag = FALSE;
		}
		i++;
	}
	if (double_flag == FALSE)
		printf("Comillas dobles cerradas o no hay\n");
	if (double_flag == TRUE)
		printf("Comillas dobles abiertas\n");
	if (single_flag == FALSE)
		printf("Comillas simples cerradas o no hay\n");
	if (single_flag == TRUE)
		printf("Comillas simples abiertas\n");
} */

void check_quotes(char *input)
{
	int	double_flag;
	int	single_flag;

	double_flag = FALSE;
	single_flag = FALSE;
	while (*input)
	{
		if (*input == '\"' && single_flag == FALSE)
		{
			input++;
			if (double_flag == TRUE)
				double_flag = FALSE;
			else
				double_flag = TRUE;
			while (*input != '\"' && *input != '\0' && *input != '\'')
				input++;
			if (*input == '\"')
				double_flag = FALSE;
		}
		if (*input == '\'' && double_flag == FALSE)
		{
			input++;
			if (single_flag == TRUE)
				single_flag = FALSE;
			else
				single_flag = TRUE;
			while (*input != '\'' && *input && *input != '\"')
				input++;
			if (*input == '\'')
				single_flag = FALSE;
		}
		input++;
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

/* int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		printf("%p\n", input);
		// TODO: Cambiar el strncmp por un strcmp
		if (!input || !ft_strcmp(input, "exit"))
			break ;
		check_quotes(input);
		free(input);
	}
	return (0);
} */
