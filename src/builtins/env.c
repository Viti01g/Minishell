/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:07:33 by drubio-m          #+#    #+#             */
/*   Updated: 2023/12/14 15:16:51 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* static void	change_pwd(t_general **gen)
{

} */

void	cmd_env(t_general *gen)
{
	int	i;
	
	i = 0;
	while (gen->env[i])
	{
		printf("%s\n", gen->env[i]);
		i++;
	}
}
