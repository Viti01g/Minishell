#include "../headers/minishell.h"


void ft_leaks(void)

{
	system("leaks -q minishell");
}

/* void split_token(char *input)
{
	t_token *tokens;
	int	i;
	int	j;
	char *fragment;

	tokens = NULL;
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
			if ((input[i] == '>' || input[i] == '<') && (input[i] == input[i + 1]))
			{
				fragment = ft_substr(input, i, 2);
				ft_lstnew_addback(&tokens, fragment);
				printf("%s\n", tokens->next->str);
				i++;
			}
			else
			{
            	fragment = ft_substr(input, i, 1);
				ft_lstnew_addback(&tokens, fragment);
				printf("%s\n", tokens->next->str);
			}
			free(fragment);
			j = i + 1;
        }
        i++;
    }
    fragment = ft_substr(input, j, i - j);
	ft_lstnew_addback(&tokens, fragment);
	printf("%s\n", tokens->next->next->str);
	free(fragment);
} */






/* int is_simple_operator(char c)
{
    return (c == '|' || c == '<' || c == '>');
}

// Función para identificar operadores dobles
int is_double_operator(char c, char next)
{
    return ((c == '>' || c == '<') && (c == next));
}

// Función para obtener fragmentos y crear tokens
void process_tokens(t_token **tokens, char *input, int start, int end)
{
    char *fragment = ft_substr(input, start, end - start);
    ft_lstnew_addback(tokens, fragment);
    free(fragment);
}

// Función principal para dividir tokens
void split_token(char *input)
{
    t_token *tokens = NULL;
	t_token *current = tokens;
    int i = 0;
    int j = 0;

    while (input[i]) {
        if (is_simple_operator(input[i])) {
            process_tokens(&tokens, input, j, i);
            free(ft_substr(input, i, 1)); // Tratar operador simple como un token
            j = i + 1;
        } else if (is_double_operator(input[i], input[i + 1])) {
            process_tokens(&tokens, input, j, i);
            free(ft_substr(input, i, 2)); // Tratar operador doble como un token
            i++;
            j = i + 1;
        }
        i++;
    }
    process_tokens(&tokens, input, j, i); // Agregar el último token
	while (current) {
    	printf("%s (%p)\n", current->str, current);
    	current = current->next;
	}
} */











void process_simple_operator(char *input, t_token **tokens, int *i, int *j)
{
    char *fragment;

	fragment = ft_substr(input, *j, *i - *j);
    ft_lstnew_addback(tokens, fragment);
    printf("%s\n", (*tokens)->str);
    free(fragment);
}

void process_double_operator(char *input, t_token **tokens, int *i)
{
    char *fragment;

	fragment = ft_substr(input, *i, 2);
    ft_lstnew_addback(tokens, fragment);
	if ((*tokens)->next != NULL)
    	printf("%s\n", (*tokens)->next->str);
    (*i)++;
	free(fragment);
}

void process_single_operator(char *input, t_token **tokens, int *i)
{
    char *fragment;

	fragment = ft_substr(input, *i, 1);
    ft_lstnew_addback(tokens, fragment);
	if ((*tokens)->next != NULL)
    	printf("%s\n", (*tokens)->next->str);
    free(fragment);
}

void split_token(char *input)
{ 
	t_token *tokens;
    int i;
    int j;

	tokens = NULL;
	i = 0;
	j = 0;
    while (input[i])
	{
        if (input[i] == '|' || input[i] == '<' || input[i] == '>') 
		{
			process_simple_operator(input, &tokens, &i, &j);
            if ((input[i] == '>' || input[i] == '<') && (input[i] == input[i + 1]))
                process_double_operator(input, &tokens, &i); 
			else 
                process_single_operator(input, &tokens, &i);
            j = i + 1;
        }
        i++;
    }
	if (j < i)
		process_simple_operator(input, &tokens, &i, &j);
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
