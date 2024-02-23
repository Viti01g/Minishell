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

int	cont_pipes(t_token **token)
{
	t_token	*aux;
	int		i;
	int		token_index;
	char	**current_words;
	aux = *token;
	token_index = 1;
	i = 0;
	while(aux != NULL)
	{
		current_words = aux->str;
		if (aux->type == PIPE)
			i++;
		aux = aux->next;
	}
	return (i);
}

int check_cmd_path(t_token *tmp, t_general *gen)
{
	t_token	*aux;

	aux = tmp;
	while (aux != NULL)
	{

		if (check_if_builtin(aux->str[0]) == 0)
		{
			if (aux->next)
				aux = aux->next;
			else
				return (0);
		}
		if (access(aux->str[0], X_OK) == 0)
			aux->path = ft_strdup(aux->str[0]);
		else if (buscar_var_env("PATH", gen->env))
			return (3); //cambiar para que devuelva un error de cmd.
		else if (aux->str && aux->type == TXT && access(aux->str[0], X_OK) != 0)   // si es tipo comando, no tiene ruta completa (comando normal = ls, cat, etc)
		{
			if (check_no_path(&gen, &tmp, &aux) == -1)
				return (-1);
		}	
		printf("ol\n");
		aux = aux->next;
	}
	return (0);
}

char	*buscar_var_env(char *var, char **env)
{
	int	i;
	int	j;

	if (!env || !var)
		return (NULL);
	j = ft_strlen(var);
	i = -1;
	while (env[++i])
	{
		if (!ft_strcmp(var, env[i]) || (!ft_strncmp(var, env[i], j)
				&& !ft_strncmp("=", env[i] + j, 1)))
			return (env[i]);
	}
	return (NULL);
}
