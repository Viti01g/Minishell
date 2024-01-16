/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:08:08 by drubio-m          #+#    #+#             */
/*   Updated: 2024/01/15 18:32:12 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_exit(t_general *gen)
{
	printf("exit\n");
	if (gen->token->words == 2)
	{
		if (ft_atoi(gen->token->str[1]))
			exit(ft_atoi(gen->token->str[1]));
		else
		{
			ft_putstr_fd("exit: numeric argument required", 2);
			exit(EB_EXIT_OUT_RANGE);
		}
	}
	if (gen->token->words > 2)
	{
		if (ft_atoi(gen->token->str[1]))
		{
			ft_putstr_fd("exit, too many arguments\n", 2);
			return ;
		}
		else
		{
			ft_putstr_fd("exit: numeric argument required", 2);
			exit(EB_EXIT_OUT_RANGE);
		}
	}
	exit(EXIT_SUCCESS);
}
