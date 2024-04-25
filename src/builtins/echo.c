/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:06:20 by drubio-m          #+#    #+#             */
/*   Updated: 2024/04/25 19:27:14 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_ex_echo(t_general *gen, int cond)
{
	int		i;
	int		h;

	i = 0;
	h = cond;
	if (cond >= 1)
		i = cond;
	while (++i < gen->token->words)
	{
		if (!ft_strcmp(gen->token->str[i], "$?"))
			printf("%d", g_signal_code);
		else if (gen->token->str[i][0])
			printf("%s", gen->token->str[i]);
		if (gen->token->str[i + 1])
			printf(" ");
	}
	if (h == 0)
		printf("\n");
}

static int	ft_find_flags(t_general *gen)
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
			break ;
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
	g_signal_code = 0;
}
