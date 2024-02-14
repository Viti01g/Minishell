#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
*EXPANDER ROADMAP:
*	1. Leer input 										(DONE)
*	2. Comprobar que después del $ haya un char			(DONE)
!	3. Comprobar si el dolar está entre comillas		//TODO
!	4. Expandir la virgulilla							//TODO
!	5. Calcular la nueva longitud del array				//TODO
!	6. Liberar el input									//TODO
!	7. Redirigir el puntero								//TODO
!	8. Tokenizar										//TODO
!	9. Eliminar comillas								//TODO
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
				ft_error("Invalid char detected");
			//***********************************************
			var = ft_substr(input, j, i - j);
			// printf("Esto vale j: %d y char: %c\n", j, input[j]);
			// printf("Esto vale i: %d y char: %c\n", i, input[i]);
			printf("Esta es tu var: %s\n", var);
			return var;
			free(var);
		}
		else if (input[i] == '$' && !(input[i + 1] == '_' || ft_isalpha(input[i + 1])))
			printf("MArico\n");
		i++;
	}
	return input;
}


