#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Añadir la excepción de la virgulilla, tiene que tener un espacio antes y después obligatoriamente

// Verifica que no haya ningún carácter inválido en la variable
/* int check_valid_var(char *str, int start, int len)
{
	while (str[start] && (str[start] == '_' || ft_isalnum(str[start])) && start < len)
		start++;
	if (start != len)
		return (1);
	else
		return (0);
} */

int check_valid_var(char *str, int start, int len)
{
    while (str[start] && start < len)
    {
        if (!(str[start] == '_' || ft_isalnum(str[start])))
            return (0); // Devuelve 0 tan pronto como encuentra un carácter inválido
        start++;
    }
    return (1); // Devuelve 1 si todos los caracteres son válidos
}

// Coje desde el dólar hasta que haya un espacio o un null para sacar la variable
void skip_until_space(char *input, int *i)
{
	while (input[*i] && input[*i] != ' ')
		(*i)++;
}

char *expander(char *input)
{
    char *new_str;
	char *var;
    int in_quotes;
	int	i;
	int j;

	i = 0;
	(void) new_str;
	(void) in_quotes;
	while (input[i])
	{
		if (input[i] == '$' && (input[i + 1] == '_' || ft_isalpha(input[i + 1])))
		{
			j = i + 1;
			skip_until_space(input, &i);
			//***********************************************
			// * Cambiar esto por la función de error
			if (!check_valid_var(input, j, i - j))
			{
				//free(var);
				printf("ERROR\n");
				return (NULL);
			}
			//**********************************************
			var = ft_substr(input, j, i - j);
			printf("Esto vale j: %d y char: %c\n", j, input[j]);
			printf("Esto vale i: %d y char: %c\n", i, input[i]);
			printf("Esta es tu var: %s\n", var);
			free(var);
		}
		else if (input[i] == '$' && !(input[i + 1] == '_' || ft_isalpha(input[i + 1])))
			printf("MArico\n");
		i++;
	}
	return input;
}


