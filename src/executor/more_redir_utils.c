/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_redir_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:35:45 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/25 21:58:35 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_file_type(t_token *tmp, t_general *gen)
{
	if (tmp->type == INFILE)
	{
		gen->infile = ft_calloc(sizeof(t_general), 1);
		if (gen->infile)
		{
			free(gen->infile);
			gen->infile = NULL;
			(gen)->infile = (tmp)->str[0];
		}
	}
	if ((tmp)->type == OUTFILE)
	{
		(gen)->outfile = ft_calloc(sizeof(t_general), 1);
		if (gen->outfile)
		{
			free(gen->outfile);
			gen->outfile = NULL;
			(gen)->outfile = (tmp)->str[0];
		}
	}
}

int	ft_open_files2(char *str, int type)
{
	int	fd;

	fd = 0;
	if (type == 0)
		fd = open(str, O_RDONLY, 0644);
	else if (type == 1)
		fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == 2)
		fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		g_signal_code = 1;
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	ft_open_files(t_token *tok, int type)
{
	int	fd;

	fd = 0;
	if (type == 0)
		fd = open(*tok->next->str, O_RDONLY, 0644);
	else if (type == 1)
		fd = open(*tok->next->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == 2)
		fd = open(*tok->next->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		g_signal_code = 1;
		exit(EXIT_FAILURE);
	}
	return (fd);
}
