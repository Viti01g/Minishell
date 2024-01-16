/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:07:00 by drubio-m          #+#    #+#             */
/*   Updated: 2024/01/16 17:00:27 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_env(t_general **gen, char *var, char *value)
{
	char	*subst;
	char	**env;
	char	**aux;

	value = ft_strjoin(var, value);
	env = ft_cpy_env((*gen)->env);
	aux = env;
	subst = "";
	while (*env)
	{
		subst = ft_strchr(*env, '=');
		if (subst)
			subst = ft_substr(*env, 0, ft_strlen(*env) - ft_strlen(subst) + 1);
		else
			subst = ft_strdup(*env);
		if (ft_strcmp(var, subst) == 0)
		{
			free(*env);
			*env = ft_strdup(value);
		}
		free(subst);
		env++;
	}
	(free(value), free_matriz((*gen)->env));
	(*gen)->env = aux;
}

char	**change_pwd(t_general *gen)
{
	char	path[PATH_MAX];

	change_env(&gen, "OLDPWD=", gen->env_pwd);
	free(gen->env_pwd);
	gen->env_pwd = ft_strdup(getcwd(path, sizeof(path)));
	change_env(&gen, "PWD=", gen->env_pwd);
	free_matriz(gen->env);
	return (gen->env);
}

void	cmd_cd(t_general *gen)
{
	char	path[PATH_MAX];
	//char	**env;

	if (getcwd(path, sizeof(path)))
	{
		ft_cpy_env(gen->env);
		gen->env = change_pwd(gen);
		chdir(gen->token->str[1]);
		printf("%s\n", getcwd(path, sizeof(path)));
	}
}
