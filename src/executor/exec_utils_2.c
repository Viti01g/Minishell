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

void	wait_child_process(t_token *token, t_general *gen)
{
	int	status;

	sig_ignore();
	while (token->next)
		token = token->next;
	if (gen->id && gen->id > 0)
	{
		waitpid(gen->id, &status, 0);
		if (WIFSIGNALED(status))
		{
			waitpid(gen->id, &status, 0);
			if (WTERMSIG(status) == 3)
				write(1, "Quit: 3", 7);
		}
	}
	while (1)
	{
		if (waitpid(-1, NULL, 0) == -1)
			break ;
	}
	sig_parent();
}

int check_cmd_path(t_token *tmp, t_general *gen)
{
	t_token	*aux;

	aux = tmp;
	while (aux != NULL)
	{
		if (check_if_builtin(aux->str[0]) == 1)
		{
			if (aux->next)
				aux = aux->next;
			else
				return (0);
		}
		if (access(aux->str[0], X_OK) == 0)
			aux->path = ft_strdup(aux->str[0]);
		else if (buscar_var_env("PATH", gen->env) == NULL)
			return (3); //cambiar para que devuelva un error de cmd.
		else if (aux->str && aux->type == CMD && access(aux->str[0], X_OK) != 0)   // si es tipo comando, no tiene ruta completa (comando normal = ls, cat, etc)
		{
			if (check_no_path(&gen, &tmp, &aux) == -1)
			{
				printf("tus mu\n");
				return (-1);
			}
		}	
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
