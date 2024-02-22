#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
*EXPANDER ROADMAP:
*	1. Leer input 										(DONE)
*	2. Comprobar que después del $ haya un char			(DONE)
*	3. Comprobar si el dólar está entre comillas		(DONE)
!	4. Calcular la nueva longitud del array				//TODO
!	5. Liberar el input									//TODO
!	6. Redirigir el puntero								//TODO
!	7. Tokenizar										//TODO
!	8. Eliminar comillas								//TODO
 */


// Devuelve 0 tan pronto como encuentra un carácter inválido
// Devuelve 1 si todos los caracteres son válidos
int check_valid_var(char *str, int start, int len)
{	
    while (str[start] && start < len)
    {
        if (!(str[start] == '_' || ft_isalnum(str[start])))
            return (0); 
        start++;
    }
    return (1);
}

// Coje desde el dólar hasta que haya un espacio o un null para sacar la variable
void skip_until_space(char *input, int *i)
{
	while (input[*i] && input[*i] != ' ')
		(*i)++;
}

void skip_until_space_or_dollar(char *input, int *i)
{
	(*i)++;
    while (input[*i] && input[*i] != ' ' && input[*i] != '$')
        (*i)++;
}

int calculate_expanded_str(char *input)
{
    int initial_len;
    int expanded_len;
    int i;
    int in_quotes;
    int var_start;

    initial_len = ft_strlen(input);
    expanded_len = 0;
    i = 0;
    in_quotes = 0;
    while(input[i])
    {
        if (input[i] == '\'')
            in_quotes = !in_quotes;
        if (input[i] == '$' && !in_quotes && (input[i + 1] == '_' || ft_isalpha(input[i + 1])))
        {
            var_start = i;
			skip_until_space_or_dollar(input, &i);
            char *var = ft_substr(input, var_start + 1, i - var_start - 1);
            char *expanded_var = getenv(var);
			printf("Este es tu output:\n %s\n\n", expanded_var);
            expanded_len += ft_strlen(expanded_var);
            free(var);
        }
        else
        {
            expanded_len += 1;
            i++;
        }
    }
    printf("Initial len: %d\n", initial_len);
    printf("Expanded len: %d\n", expanded_len);
    return expanded_len;
}

char *expander(char *input)
{
	char *new_str;
	char *var;
	int in_quotes;
	int i;
	int j;

	i = 0;
	in_quotes = 0;
	(void) new_str;
	while (input[i])
	{
		if (input[i] == '\'')
			in_quotes = !in_quotes;
		else if (input[i] == '$' && !in_quotes && (input[i + 1] == '_' || ft_isalpha(input[i + 1])))
		{
			j = i + 1;
			skip_until_space(input, &i);
			// if (!check_valid_var(input, j, i - j))
			// 	ft_error("Invalid char detected");
			var = ft_substr(input, j, i - j);
			printf("Esta es tu var: %s\n", var);
			return var;
			free(var);
		}
		else if (input[i] == '$' && !in_quotes && !(input[i + 1] == '_' || ft_isalpha(input[i + 1])))
			printf("MArico\n");
		i++;
	}
	return input;
}
