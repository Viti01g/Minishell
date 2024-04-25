/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_parent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:57:09 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/24 16:57:12 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_input(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_sign(void)
{
	signal(SIGINT, &signal_input);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_parent(void)
{
	signal(SIGINT, &signal_input);
	signal(SIGQUIT, SIG_IGN);
}
