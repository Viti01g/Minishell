# include "minishell.h"

static char **ft_ord_alf(char **env)
{
	int		i;
	int		j;
	int		len;
	char	*aux;

	i = 0;
	len = count_txt(env);
	while (i < len)
	{
		j = -1;
		while (++j < (len - i - 1))
		{
			aux = env[j];
			if (ft_strcmp(env[j], env[j + 1]) > 0)
			{
				aux = env[j];
				env[j] = env[j + 1];
				env[j + 1] = aux;
			}
		}
		i++;
	}
	return (env);
}

void	ft_print_export(t_general *gen)
{
	int		i;
	char	**env_alf;

	i = -1;
	env_alf = ft_ord_alf(gen->env);
	while (env_alf[++i])
		printf("declare -x %s\n", env_alf[i]);
}
