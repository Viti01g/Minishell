#include "minishell.h"

t_token	*ft_lstnew_addback(t_token **token, char *str, int type)
{
	t_token	*new;
	t_token	*end;

	if (!token || !str)
		return (NULL);
	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->str = ft_split(str, ' ');
	new->words = count_words(new->str);
	new->type = type;
	new->next = NULL;
	if (*token == NULL)
		*token = new;
	else
	{
		end = *token;
		while (end->next != NULL)
			end = end->next;
		end->next = new;
	}
	return (new);
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;
	int		i;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		i = -1;
		while (tmp->str[++i])
			free(tmp->str[i]);
		free(tmp->str);
		free(tmp);
	}
}