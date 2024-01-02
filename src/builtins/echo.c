/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: VR <VR@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:06:20 by drubio-m          #+#    #+#             */
/*   Updated: 2024/01/02 20:30:51 by VR               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_expand_echo(t_general *gen, char *var/* , int pos */)
{
	int	i;
	int	j;

	i = -1;
	var++;
	while (gen->env[++i])
	{
		j = ft_strlen(var);
		if (!ft_strncmp(gen->env[i], var, ft_strlen(var)))
		{
			return (ft_substr(gen->env[i], j + 1, ft_strlen(gen->env[i]) - j));
		}
	}
	return ("");
}

static void	ft_ex_echo(t_general *gen, int cond)
{
	int		i;
	char	*var;
	int	h;

	i = 0;
	h = cond;
	if (cond >= 1)
		i = cond;
	while (++i < gen->token->words)
	{
		if (gen->token->str[i][0] != '$')
			printf("%s", gen->token->str[i]);
		if (gen->token->str[i][0] == '$')
		{
			var = gen->token->str[i];
			printf("%s", ft_expand_echo(gen, var));
		}
		if (!ft_strcmp(gen->token->str[i], "$?"))
			printf("%d", signal_code);
		if (gen->token->str[i + 1])
			printf(" ");
	}
	if (h == 0)
		printf("\n");
}

static int ft_find_flags(t_general *gen)
{
	int	i;
	int	j;

	i = 1;
	while (gen->token->str[i] && gen->token->str[i][0] == '-')
	{
		j = 1;
		while (gen->token->str[i][j] && gen->token->str[i][j] == 'n')
			j++;
		if (!gen->token->str[i][j])
			i++;
		else
			break;
	}
	return (i - 1);
}

void	cmd_echo(t_general *gen)
{
	if (gen->token->words == 1)
	{
		printf("\n");
		return ;
	}
	ft_ex_echo(gen, ft_find_flags(gen));
}
