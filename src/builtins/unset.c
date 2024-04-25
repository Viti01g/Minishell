/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:54:35 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/24 16:54:37 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	find_in_env(char **env, char ***env_cpy, char *str)
{
	char	*substr;
	char	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
	{
		aux = ft_strchr(env[i], '=');
		if (aux)
			substr = ft_substr(env[i], 0, ft_strlen(env[i]) - ft_strlen(aux));
		else
			substr = ft_strdup(env[i]);
		if (ft_strcmp(str, substr) != 0)
			(*env_cpy)[j++] = env[i];
		else
			free(env[i]);
		i++;
		free(substr);
	}
}

void	cmd_unset(t_general *gen)
{
	int		i;
	char	**env;
	char	**env_cpy;

	i = -1;
	env = ft_cpy_env(gen->env);
	while (gen->token->str[++i])
	{
		if (ft_strlen(gen->token->str[i]) != 0)
		{
			env_cpy = ft_calloc(count_txt(env) + 1, sizeof(char *));
			find_in_env(env, &env_cpy, gen->token->str[i]);
			free(env);
			env = env_cpy;
		}
	}
	free_matriz(gen->env);
	gen->env = env;
	g_signal_code = 0;
}
