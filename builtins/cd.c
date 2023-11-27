/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:07:00 by drubio-m          #+#    #+#             */
/*   Updated: 2023/11/24 12:01:18 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	cmd_cd(char **line)
{
	(void)line;
	t_general	*gen;
	char		path[PATH_MAX];

	gen = &g_gen;
	if (getcwd(path, sizeof(path)))
	{
		
	}
}
