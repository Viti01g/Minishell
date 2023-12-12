#include "minishell.h"

void	init_vars(t_general *gen, char **env)
{
	char	path[PATH_MAX];

	gen->env = ft_cpy_env(env);
	gen->env_path = ft_cpy_path(env);
	gen->env_home = ft_cpy_home(env);
	gen->env_pwd = ft_strdup(getcwd(path, sizeof(path)));
	gen->env_oldpwd = ft_cpy_oldpwd(env);
}
