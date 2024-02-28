# include "minishell.h"

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	return (pid);
}

static int	is_absolute_path(const char *path)
{
	if (!path || path[0] == '\0')
		return (0);
	return (1);
}

int	ft_is_builtin(t_token *token, t_general *gen)
{
	if (buscar_var_env("PATH", gen->env) != NULL)
	{
		if (is_absolute_path(*token->str) == 0)
		{
			if (token->path)
				free(token->path);
			token->path = find_in_path(token, gen);
		}
	}
	if ((ft_strncmp(token->str[0], "cd\0", 3) == 0)
		|| (ft_strncmp(token->str[0], "pwd\0", 4) == 0)
		|| (ft_strncmp(token->str[0], "echo\0", 5) == 0)
		|| (ft_strncmp(token->str[0], "env\0", 4) == 0)
		|| (ft_strncmp(token->str[0], "export\0", 7) == 0)
		|| (ft_strncmp(token->str[0], "unset\0", 6) == 0)
		|| (ft_strncmp(token->str[0], "exit\0", 5) == 0))
		return (0);
	else
		return (1);
}
