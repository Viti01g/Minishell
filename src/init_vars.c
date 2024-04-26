/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:59:22 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/26 10:26:15 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_vars(t_general *gen, char **env, char **view)
{
	int		i;
	char	path[PATH_MAX];

	*view = "a";
	i = 0;
	gen->token = NULL;
	gen->infile = NULL;
	gen->delim = NULL;
	gen->env = NULL;
	gen->env = ft_cpy_env(env);
	gen->env_path = ft_cpy_path(env);
	gen->env_home = ft_cpy_home(env);
	if (!env[i])
		ft_cpy_pwd(&gen, env);
	else
		gen->env_pwd = ft_strdup(getcwd(path, sizeof(path)));
	gen->env_oldpwd = ft_cpy_oldpwd(env);
}
