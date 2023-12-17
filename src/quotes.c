#include "minishell.h"


// TODO: Checkear que las comillas estén cerradas
// TODO: Manejar las comillas anidadas
// TODO: Manejar que me detecte los argumentos de los comandos bien
	// TODO: ejemplo: echo "hola mundo" solo tiene un arg no 2
void check_quotes(char *input)
{
	int	double_flag;
	int	single_flag;
	int	decide;
	int flag;

	double_flag = FALSE;
	single_flag = FALSE;
	decide = FALSE;
	flag = FALSE;
	while (*input)
	{
		if (*input == '\"' && single_flag == FALSE)
		{
			if (flag == FALSE)
			{
				decide = TRUE;
				flag = TRUE;
			}
			input++;
			if (double_flag == TRUE)
				double_flag = FALSE;
			else
				double_flag = TRUE;
			while (*input != '\"' && *input != '\0')
				input++;
			if (*input == '\"')
				double_flag = FALSE;
		}
		if (*input == '\'' && double_flag == FALSE)
		{
			if (flag == FALSE)
			{
				decide = FALSE;
				flag = TRUE;
			}
			input++;
			if (single_flag == TRUE)
				single_flag = FALSE;
			else
				single_flag = TRUE;
			while (*input != '\'' && *input)
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
	if (decide == FALSE)
		printf("Va a ser interpretado con comillas simples\n");
	else
		printf("Va a ser interpretado con comillas dobles\n");
}

int	main(void)
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
}
