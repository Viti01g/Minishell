/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:56:41 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/26 10:46:12 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_disable_ctrl_c_printing_chars(void)
{
	t_inf	inf;
	int		rc;

	rc = tcgetattr(0, &inf.termios);
	if (rc != 0)
	{
		perror("tcgetattr");
		exit (1);
	}
	inf.termios.c_lflag &= ~ECHOCTL;
	rc = tcsetattr(0, 0, &inf.termios);
	if (rc != 0)
	{
		perror("tcsetattr");
		exit(1);
	}
}

void	ft_signal_quit(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
}

void	ft_signal_reset_prompt(int signal)
{
	(void) signal;
	g_signal_code = 130;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_signal_interrupt(void)
{
	struct sigaction	act;

	memset(&act, 0, sizeof(act));
	act.sa_handler = &ft_signal_reset_prompt;
	sigaction(SIGINT, &act, NULL);
}

void	ft_signals(void)
{
	ft_signal_interrupt();
	ft_signal_quit();
}
