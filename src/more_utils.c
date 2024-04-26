/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:04:31 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/25 20:59:49 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_per(char *var, char *s, int i)
{
	ft_putstr_fd(var, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(s);
	g_signal_code = i;
}

void	ft_put_msg(char *var, char *s)
{
	ft_putstr_fd(var, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	g_signal_code = 127;
}

void	ft_err_msg(char *s)
{
	ft_putendl_fd(s, 2);
	g_signal_code = 1;
}

int	error_quote(int code)
{
	printf("Quotes are not closed\n");
	g_signal_code = 1;
	return (code);
}
