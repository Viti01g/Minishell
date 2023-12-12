/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:07:00 by drubio-m          #+#    #+#             */
/*   Updated: 2023/12/12 17:02:15 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* static void	change_pwd(t_general **gen)
{
	int		i;
	char	Path[PATH_MAX];

	(void)gen;
	g_gen.env_oldpwd = g_gen.env_pwd;
	g_gen.env_pwd = getcwd(Path, sizeof(Path));
	i = -1;
	while (g_gen.env[++i])
	{
		;
	}
} */

void	cmd_cd(char **line)
{
	(void)line;
	char		path[PATH_MAX];

	if (getcwd(path, sizeof(path)))
	{
		//change_pwd(&gen);
		printf("si\n");
		printf("Donde tendria que ir: %s\n", g_gen.token->str[1]);
		printf("si\n");
		chdir(g_gen.token->str[1]);
		printf("%s\n", getcwd(path, sizeof(path)));
	}
}
