#include "../headers/minishell.h"

/* t_token	*ft_lstnew_addback(t_token **token, char *str)
{
	t_token	*new;
	//char	**content;

	if (!token)
		return (NULL);
	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	if (*token == NULL)
		*token = new;
	else
	{
		t_token	*end = *token;
		while (end->next != NULL)
			end = end->next;
		end->next = new;
	}
	return (new);
} */

t_token *ft_lstnew_addback(t_token **token, char *str)
{
    t_token *new;

    if (!token || !str)
        return (NULL);

    new = malloc(sizeof(t_token));
    if (!new)
        return (NULL);

    new->str = ft_split(str, ' '); // Aquí se asume una función ft_split para dividir la cadena por espacios
    new->next = NULL;

    if (*token == NULL)
        *token = new;
    else {
        t_token *end = *token;
        while (end->next != NULL)
            end = end->next;
        end->next = new;
    }

    return new;
}
