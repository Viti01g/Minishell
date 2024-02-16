#include "minishell.h"

t_token	*copy_no_pipe(t_token *token)
{
	t_token	*new_head;
	t_token	*struct_cpy;
	t_token	*current_new;
	t_token	*new_node;

	new_head = NULL;
	struct_cpy = token;
	current_new = NULL;
	while (struct_cpy != NULL)
	{
		if (struct_cpy->type != PIPE)
		{
			new_node = (t_token *)malloc(sizeof(t_token));
			if (new_node == NULL)
				return (NULL);
			new_node->str = struct_cpy->str;
			new_node->type = struct_cpy->type;
			new_node->path = struct_cpy->path;
			new_node->next = NULL;
			set_nodes(&new_head, &new_node, &current_new);
		}
		struct_cpy = struct_cpy->next;
	}
	printf("so\n");
	return (new_head);
}

void	set_nodes(t_token **new_head, t_token **new_node, t_token **current_new)
{
	if ((*new_head) == NULL)
	{
		(*new_head) = (*new_node);
		(*current_new) = (*new_node);
	}
	else
	{
		(*current_new)->next = (*new_node);
		(*current_new) = (*new_node);
	}
}

int	cont_pipes(t_token *token)
{
	t_token *aux;
	int	i;

	printf("token token: %s\n", token->str[0]);
	printf("token next: %s\n", token->next->str[0]);
	aux = token;
	i = 0;
	while (aux)
	{
	printf("si\n");
		printf("token aux: %s\n", aux->str[0]);
		if (aux->type == PIPE)
		{
			printf("token: %s\n", aux->str[0]);
			printf("entro\n");
			i++;
		}
		aux = aux->next;
	}
	printf("num de pipes: %d\n", i);
	return (i);
}
