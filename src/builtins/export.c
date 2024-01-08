/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: VR <VR@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:08:20 by drubio-m          #+#    #+#             */
/*   Updated: 2024/01/03 20:35:05 by VR               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	cmd_export(t_general *gen)
{
	int	i;
	enum e_expt	result;
	char **env;

	i = 0;
	if (gen->args == 1)
		ft_print_export(gen);
	else
	{
		while (gen->token->str[i])
		{
			env = ft_cpy_env(gen->env);
			result = ft_validate(gen->token->str[1]);
			if (result == FAIL)
				return (invalid_value(env));
			else
			{
				free_matriz(gen->env);
				//cojer el env otra vez
			}
		}
	}
}
