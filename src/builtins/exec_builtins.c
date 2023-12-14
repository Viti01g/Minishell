/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:07:57 by drubio-m          #+#    #+#             */
/*   Updated: 2023/12/14 17:12:56 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_buitins(t_general *gen)
{
	if (!ft_strncmp(gen->token->str[0], "cd", ft_strlen(gen->token->str[0])))
		cmd_cd(gen);
	else if (!ft_strncmp(gen->token->str[0], "env", ft_strlen(gen->token->str[0])))
		cmd_env(gen);
	else if (!ft_strncmp(gen->token->str[0], "pwd", ft_strlen(gen->token->str[0])))
		cmd_pwd(gen);
	else if (!ft_strncmp(gen->token->str[0], "exit", ft_strlen(gen->token->str[0])))
		cmd_exit(gen);
	else if (!ft_strncmp(gen->token->str[0], "echo", ft_strlen(gen->token->str[0])))
		cmd_echo(gen);
	else if (!ft_strncmp(gen->token->str[0], "unset", ft_strlen(gen->token->str[0])))
		cmd_unset(gen);
	else if (!ft_strncmp(gen->token->str[0], "export", ft_strlen(gen->token->str[0])))
		cmd_export(gen);
	else
		return ;
}
