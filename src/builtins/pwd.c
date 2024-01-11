/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:08:31 by drubio-m          #+#    #+#             */
/*   Updated: 2024/01/11 18:17:37 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_pwd(t_general *gen)
{
	(void)gen;
	char	path[PATH_MAX];

	printf("%s\n", getcwd(path, sizeof(path)));
}
