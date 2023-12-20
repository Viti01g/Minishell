/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:06:20 by drubio-m          #+#    #+#             */
/*   Updated: 2023/12/20 19:38:13 by vruiz-go         ###   ########.fr       */
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
	return ("fallo");
}

static void	ft_ex_echo(t_general *gen, int cond)
{
	int		i;
	char	*var;

	i = 0;
	if (cond == 1)
		i++;
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
}

void	cmd_echo(t_general *gen)
{
	//(void)gen;
	if (gen->token->words == 1)
	{
		printf("\n");
		return ;
	}
	if (!ft_strcmp(gen->token->str[1], "-n"))
		ft_ex_echo(gen, 1);
	else
	{
		ft_ex_echo(gen, 0);
		printf("\n");
	}
}
