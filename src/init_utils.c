/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:02:03 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/24 18:45:03 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_cpy_env(char **env)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = NULL;
	if (!env[i])
		return (str);
	while (env[i])
		i++;
	str = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env[++i])
		str[i] = malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
	i = -1;
	while (env[++i])
	{
		j = -1;
		while (env[i][++j])
			str[i][j] = env[i][j];
		str[i][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}

char	*ft_cpy_home(char **env)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "HOME=", 5))
			str = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
		if (str)
			break ;
		i++;
	}
	return (str);
}

char	*ft_cpy_path(char **env)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			str = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
		if (str)
			break ;
		i++;
	}
	return (str);
}

char	*ft_cpy_pwd(t_general **gen, char **env)
{
	int		i;
	char	*str;
	char	**envi;
	char	path[PATH_MAX];

	envi = NULL;
	str = NULL;
	i = 0;
	if (!env[i])
	{
		envi = ft_calloc(i + 2, sizeof(char *));
		envi[i] = ft_strjoin("PWD=", getcwd(path, sizeof(path)));
		(*gen)->env = envi;
	}
	while (env[i])
	{
		str = getcwd(path, sizeof(path));
		if (str)
			break ;
		i++;
	}
	return (str);
}

char	*ft_cpy_oldpwd(char **env)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "OLDPWD=", 7))
			str = ft_substr(env[i], 5, ft_strlen(env[i]) - 7);
		if (str)
			break ;
		i++;
	}
	return (str);
}
