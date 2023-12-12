/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:07:33 by drubio-m          #+#    #+#             */
/*   Updated: 2023/11/23 19:53:40 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/* static void	change_pwd(t_general **gen)
{

} */

void	cmd_env(char **line)
{
	(void)line;
	t_general *gen;
	int	i;
	
	gen = &g_gen;
	i = 0;
	while (gen->env[i])
	{
		printf("%s\n", gen->env[i]);
		i++;
	}
}
