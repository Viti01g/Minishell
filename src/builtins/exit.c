/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:08:08 by drubio-m          #+#    #+#             */
/*   Updated: 2023/12/19 15:44:43 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_exit(t_general *gen)
{
	if (gen->token->words == 2)
		exit(ft_atoi(gen->token->str[1]));
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
