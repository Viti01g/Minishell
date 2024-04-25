/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:48:19 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/24 16:54:18 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_ord_alf(char **env)
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

int	invalid_value(char **env)
{
	free_matriz(env);
	ft_putstr_fd("Invalid identifier\n", 2);
	return (1);
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
