/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:07:57 by drubio-m          #+#    #+#             */
/*   Updated: 2023/12/12 17:02:46 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_buitins(char **line)
{
	if (!ft_strncmp(line[1], "cd", ft_strlen(line[1])))
		cmd_cd(line);
	else if (!ft_strncmp(line[1], "env", ft_strlen(line[1])))
		cmd_env(line);
	else if (!ft_strncmp(line[1], "pwd", ft_strlen(line[1])))
		cmd_pwd(line);
	else if (!ft_strncmp(line[1], "exit", ft_strlen(line[1])))
		cmd_exit(line);
	else if (!ft_strncmp(line[1], "echo", ft_strlen(line[1])))
		cmd_echo(line);
	else if (!ft_strncmp(line[1], "unset", ft_strlen(line[1])))
		cmd_unset(line);
	else if (!ft_strncmp(line[1], "export", ft_strlen(line[1])))
		cmd_export(line);
}
