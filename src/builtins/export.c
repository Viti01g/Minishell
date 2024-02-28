/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:08:20 by drubio-m          #+#    #+#             */
/*   Updated: 2024/02/28 17:15:45 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value_for_var(char *str)
{
	char	*aux;
	char	*var;

	aux = ft_strchr(str, '=');
	if (aux != 0)
		var = ft_substr(str, 0, ft_strlen(str) - ft_strlen(aux));
	else
		var = ft_strdup(str);
	return (var);
}

static int	ft_find_in_env(char **env, char ***env_cpy, char *str)
{
	char	*substr;
	int		flag;
	int		i;
	char	*aux;

	i = 0;
	flag = -1;
	while (*env)
	{
		aux = ft_strchr(*env, '=');
		if (aux)
			substr = ft_substr(*env, 0, ft_strlen(*env) - ft_strlen(aux));
		else
			substr = ft_strdup(*env);
		if (ft_strcmp(str, substr) == 0)
			flag = i;
		free(substr);
		(*env_cpy)[i++] = *env++;
	}
	return (flag);
}

static enum e_expt	ft_validate(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '=')
		return (FAIL);
	while (str[++i] && str[i] != '=')
	{
		if (i == 0 && !(ft_isalpha(str[i]) || str[i] == '_'))
			return (FAIL);
		else if (i != 0 && !(ft_isalnum(str[i]) || str[i] == '_'))
			return (FAIL);
	}
	if (str[i] == '\0')
		return (CREATE);
	return (NEW_VALUE);
}

char	**ft_change_env(char **env, char *str, enum e_expt flag)
{
	char	**new_env;
	char	*var;
	int		exists;

	if (ft_strlen(str) < 1)
		return (env);
	new_env = ft_calloc(count_txt(env) + 2, sizeof(char *));
	var = get_value_for_var(str);
	exists = ft_find_in_env(env, &new_env, var);
	free(var);
	if (exists == -1)
	{
		new_env[count_txt(env)] = ft_strdup(str);
		free(env);
		env = new_env;
	}
	else if (flag == NEW_VALUE)
	{
		(free(env[exists]), free(new_env));
		env[exists] = ft_strdup(str);
	}
	else
		free(new_env);
	return (env);
}

void	cmd_export(t_general *gen)
{
	int	i;
	enum e_expt	result;
	char **env;
	int	flag;

	i = -1;
	if (gen->args == 1)
		return(ft_print_export(gen));
	while (gen->token->str[++i])
	{
		env = ft_cpy_env(gen->env);
		result = ft_validate(gen->token->str[1]);
		if (result == FAIL)
			flag = invalid_value(env);
		else
		{
			free_matriz(gen->env);
			gen->env = ft_change_env(env, gen->token->str[1], result);
		}
	}
	g_signal_code = flag;
}
