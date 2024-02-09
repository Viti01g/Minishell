#include "minishell.h"

static void	ft_update(t_general *gen)
{
	int		i;
	char	*pwd;
	char	*oldpwd;

	pwd = ft_strjoin("PWD=", gen->env_pwd);
	oldpwd = ft_strjoin("OLDPWD=", gen->env_oldpwd);
	i = -1;
	while (gen->env[++i])
	{
		if (!ft_strncmp(gen->env[i], "PWD=", 4))
		{
			free(gen->env[i]);
			gen->env[i] = ft_strdup(pwd);
		}
		if (!ft_strncmp(gen->env[i], "OLDPWD=", 7))
		{
			free(gen->env[i]);
			gen->env[i] = ft_strdup(oldpwd);
		}
	}
	free(pwd);
	free(oldpwd);
}

static void	ft_new_pwd(t_general *gen, char *old_pwd, char *new_pwd)
{
	free(gen->env_pwd);
	free(gen->env_oldpwd);
	gen->env_pwd = ft_strdup(new_pwd);
	gen->env_oldpwd = ft_strdup(old_pwd);
	ft_update(gen);
}

void	cmd_cd(t_general *gen)
{
	char	new_pwd[PATH_MAX];
	char	*old_pwd;

// char *path = ft_strjoin(gen->env_home, ft_strchr(gen, '~') + 1);
// str_append  = realloc src
// capacidad

// char_append = realloc src
	if (!gen->token->str[1] || (gen->token->str[1][0] == '~' && ft_strlen(gen->token->str[1]) == 1))
	{
		if (chdir(gen->env_home) != 0)
			exit(EXIT_FAILURE);
	}
	else if (gen->token->str[1][0] == '-')
	{
		if (chdir(gen->env_oldpwd) != 0)
			exit(EXIT_FAILURE);
	}
	else if (chdir(gen->token->str[1]) != 0)
		exit(EXIT_FAILURE);
	old_pwd = ft_strdup(gen->env_pwd);
	if (getcwd(new_pwd, sizeof(new_pwd) - 1))
		ft_new_pwd(gen, old_pwd, new_pwd);
}
