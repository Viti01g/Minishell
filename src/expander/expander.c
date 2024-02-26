#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*EXPANDER ROADMAP:
*	1. Leer input 										(DONE)
*	2. Comprobar que después del $ haya un char			(DONE)
*	3. Comprobar si el dólar está entre comillas		(DONE)
*	4. Calcular la nueva longitud del array				(DONE)
*	5. Liberar el input									(DONE)
*	6. Redirigir el puntero								(DONE)
!	7. Tokenizar										//TODO
!	8. Eliminar comillas								//TODO
 */

// Coje desde el dólar hasta que haya un espacio 
// o un null para sacar la variable
void	skip_until_space(char *input, int *i)
{
	while (input[*i] && input[*i] != ' ')
		(*i)++;
}

void	skip_until_space_or_dollar(char *input, int *i)
{
	(*i)++;
	while (input[*i] && input[*i] != ' '
		&& input[*i] != '$' && input[*i] != '\"')
		(*i)++;
}

char	*aux_calculate(char *input, int *i)
{
	int		var_start;
	char	*var;
	char	*expanded_var;

	var_start = *i;
	skip_until_space_or_dollar(input, i);
	var = ft_substr(input, var_start + 1, *i - var_start - 1);
	expanded_var = getenv(var);
	free(var);
	return (expanded_var);
}

int	calculate_expanded_str(char *input)
{
	int		i;
	int		in_quotes;
	int		expanded_len;
	char	*expanded_var;

	i = 0;
	in_quotes = 0;
	expanded_len = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			in_quotes = !in_quotes;
		if (input[i] == '$' && !in_quotes
			&& (input[i + 1] == '_' || ft_isalpha(input[i + 1])))
		{
			expanded_var = aux_calculate(input, &i);
			expanded_len += ft_strlen(expanded_var);
		}
		else
		{
			expanded_len += 1;
			i++;
		}
	}
	return (expanded_len);
}

char	*expander(char *input)
{
	char	*result;

	result = create_and_fill_array(input);
	return (result);
}
