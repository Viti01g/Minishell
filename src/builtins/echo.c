/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:06:20 by drubio-m          #+#    #+#             */
/*   Updated: 2023/12/19 13:16:52 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_ex_echo(t_general *gen, int cond)
{
	int	i;

	i = 0;
	if (cond == 1)
		i++;
	while (++i < gen->token->words)
	{
		if (gen->token->str[i][0] != '$')
			printf("%s", gen->token->str[i]);
		if (!ft_strcmp(gen->token->str[i], "$?"))
			printf("hola\n");
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
