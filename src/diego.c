#include "../headers/minishell.h"

void ft_leaks(void)
{
	system("leaks -q minishell");
}

void split_token(char *input)
{
	t_token *tokens = NULL;
	int	i;
	int	j;
	char *fragment;

	i = 0;
	j = 0;
	while (input[i])
	{
        if (input[i] == '|' || input[i] == '<' || input[i] == '>') 
		{
			fragment = ft_substr(input, j, i - j);
			ft_lstnew_addback(&tokens, fragment);
			printf("%s\n", tokens->str);
			free(fragment);
          //  printf("Token:%s\n", fragment);
			if ((input[i] == '>' || input[i] == '<') && input[i] == input[i + 1])
			{
				fragment = ft_substr(input, i, 2);
				ft_lstnew_addback(&tokens, fragment);
				printf("%s\n", tokens->next->str);
				//printf("Token:%s\n", fragment);
				i++;
			}
			else
			{
            	fragment = ft_substr(input, i, 1);
				ft_lstnew_addback(&tokens, fragment);
				printf("%s\n", tokens->next->str);
           // 	printf("Token:%s\n", fragment);
			}
			free(fragment);
			j = i + 1;
        }
        i++;
    }
    fragment = ft_substr(input, j, i - j);
	ft_lstnew_addback(&tokens, fragment);
	printf("%s\n", tokens->next->next->str);
   // printf("Token:%s\n", fragment);
	free(fragment);
}

int	main(void) 
{
    char *input;

	atexit(ft_leaks);
    while (1) 
	{
        input = readline("\e[1;32mminishell$ \e[0m");
		printf("%p\n", input);
        if (!input) 
            break ;
		split_token(input);
		free(input);
    }
	return 0;
}

/* 
	*Pasos para almacenarlo en la lista

	1: Mandar a la función de crear nodo, un char * 
	al cual se le haga un split por espacios y se guarde en una matriz
	
	2. Una vez hecho el split ir guardando en cada nodo de la lista, diciendo si es o no operador

 */

/* 
	TODO: guardar en una lista enlazada
 
 */
