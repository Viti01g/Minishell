/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:33:42 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/13 12:44:47 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pos_path(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (!strncmp(env[i], "PATH=", 5))
			return (i);
	}
	return (-1);
}

char	*find_in_path(t_token *toke, t_general *gen)
{
	char	**cmds;
	char	*barra_cmd;
	int		path;
	int		i;
	t_token	*aux;

	aux = toke;
	if (access(*aux->str, X_OK) == 0)
		return (*aux->str);
	path = pos_path(gen->env);
	if (path == -1)
		return (NULL);
	cmds = ft_split(gen->env[path] + 5, ':');
	i = -1;
	while (cmds[++i])
	{
		barra_cmd = ft_strjoin("/", *aux->str);
		aux->path = ft_strjoin(cmds[i], barra_cmd);
		free(barra_cmd);
		if (access(aux->path, X_OK) == 0)
			return (free_matriz(cmds), aux->path);
		free(aux->path);
	}
	free_matriz(cmds);
	return (NULL);
}

static void	no_path(t_token **token, t_token **tmp)
{
	t_token	*head;
	t_token	*aux;

	head = (*token);
	aux = (*token);
	(*tmp) = head;
	while ((*tmp) && (*tmp)->next)
	{
		if ((*tmp)->next)
			aux = (*tmp)->next;
		if ((*tmp)->path)
			free((*tmp)->path);
		(*tmp) = aux;
	}
}

int	check_no_path(t_general **gen, t_token **toke, t_token **aux)
{
	char	*str;

	(*aux)->path = find_in_path(*aux, *gen);
	if (!(*aux)->path)
	{
		str = (*aux)->str[0];
		return (no_path(toke, aux), ft_put_msg((*gen)->token->str[0],
				"command not found\n"), -1);
	}
	return (0);
}

int	check_if_builtin(char *str)
{
	if (ft_strcmp(str, "cd") == 0)
		return (1);
	else if (ft_strcmp(str, "echo") == 0)
		return (1);
	else if (ft_strcmp(str, "env") == 0)
		return (1);
	else if (ft_strcmp(str, "exit") == 0)
		return (1);
	else if (ft_strcmp(str, "export") == 0)
		return (1);
	else if (ft_strcmp(str, "pwd") == 0)
		return (1);
	else if (ft_strcmp(str, "unset") == 0)
		return (1);
	return (0);
}
