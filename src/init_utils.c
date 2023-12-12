#include "minishell.h"

char **ft_cpy_env(char **env)
{
	int	i;
	int j;
	char **str;

	i = 0;
	j = 0;
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
		while(env[i][++j])
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
			break;
		i++;
	}
/* 	if (!str)
	{
		ft_putstr_fd("Error: can't find HOME\n", STDERR_FILENO);
		exit (1);
	} */
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
			break;
		i++;
	}
/* 	if (!str)
	{
		ft_putstr_fd("Error: can't find PATH\n", STDERR_FILENO);
		exit (1);
	} */
	return (str);
}

char	*ft_cpy_pwd(char **env)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
			str = ft_substr(env[i], 5, ft_strlen(env[i]) - 4);
		if (str)
			break;
		i++;
	}
/* 	if (!str)
	{
		ft_putstr_fd("Error: can't find PWD\n", STDERR_FILENO);
		exit (1);
	} */
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
			break;
		i++;
	}
	/* if (!str)
	{
		ft_putstr_fd("Error: can't find OLDPWD\n", STDERR_FILENO);
		exit (1);
	} */
	return (str);
}