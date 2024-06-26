/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:36:01 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/10 17:22:27 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mayor_sign(t_token *tok, t_general *gen)
{
	int	file;

	file = 0;
	if (tok->type == FLCH_DRCH || tok->type == D_FLCH_DRCH)
	{
		if (tok->type == FLCH_DRCH)
		{
			gen->dch = tok->str[0];
			file = ft_open_files(tok, 1);
		}
		if (tok->type == D_FLCH_DRCH)
		{
			gen->db_dch = tok->str[0];
			file = ft_open_files(tok, 2);
		}
		close(file);
	}
}

void	minor_sign(t_token *tok, t_general *gen)
{
	int	file;

	file = 0;
	if (tok->type == FLCH_IZQ || tok->type == D_FLCH_IZQ)
	{
		if (tok->type == FLCH_IZQ)
		{
			gen->izq = tok->str[0];
			if (tok->next->type == INFILE)
				gen->infile = tok->next->str[0];
			if (access(gen->infile, F_OK) == -1)
			{
				ft_error("Error opening infile");
				g_signal_code = 1;
				gen->infile = NULL;
			}
		}
		else if (tok->type == D_FLCH_IZQ)
		{
			gen->db_izq = tok->str[0];
			gen->delim = tok->next->str;
		}
	}
}

int	ft_is_redir(int type)
{
	if (type >= 1 && type <= 4)
		return (0);
	return (1);
}

void	check_redirs(t_token *tok, t_general *gen)
{
	t_token	*aux;

	aux = tok;
	while (aux)
	{
		if (!ft_is_redir(aux->type))
		{
			mayor_sign(aux, gen);
			minor_sign(aux, gen);
		}
		ft_file_type(aux, gen);
		aux = aux->next;
	}
}
