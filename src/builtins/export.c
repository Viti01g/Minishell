/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:08:20 by drubio-m          #+#    #+#             */
/*   Updated: 2023/12/14 20:02:49 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	ft_print_export(t_general *gen)
{
	int		i;
	char	**env_alf;

	i = -1;
	env_alf = ft_ord_alf(gen->env);
	while (env_alf[++i])
		printf("declare -x %s\n", env_alf[i]);
}

void	cmd_export(t_general *gen)
{
//	int	i;

//	i = 0;
	if (gen->args == 1)
		ft_print_export(gen);
}
