#include "minishell.h"

void	init_vars(t_general *gen, char **env)
{
	int		i;
	char	path[PATH_MAX];

	i = 0;
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
