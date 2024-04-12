/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:32:34 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/10 15:46:47 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				write(1, "Quit: 3\n", 8);
		}
	}
	while (1)
	{
		if (waitpid(-1, NULL, 0) == -1)
			break ;
	}
	sig_parent();
}

int	check_cmd_path(t_token *tmp, t_general *gen)
{
	t_token	*au;

	au = tmp;
	while (au != NULL)
	{
		if (check_some_built(au) == 0)
			return (0);
		if (access(au->str[0], X_OK) == 0)
			au->path = ft_strdup(au->str[0]);
		else if (buscar_var_env("PATH", gen->env) == NULL)
			return (ft_put_msg(gen->token->str[0], "command not found\n"), -1);
		else if (au->type == D_FLCH_IZQ && au->next)
			au->next->type = DELM;
		else if (au->str && au->type == CMD && access(au->str[0], X_OK) != 0)
		{
			if (check_no_path(&gen, &tmp, &au) == -1)
				return (-1);
		}
		au = au->next;
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
