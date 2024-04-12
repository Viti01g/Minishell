/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:34:16 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/10 13:34:19 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_heredocs(t_token *token, t_general *gen)
{
	int		i;
	t_token	*aux;

	i = 0;
	aux = token;
	while (aux && aux->next)
	{
		if (aux->type == D_FLCH_IZQ)
			i++;
		aux = aux->next;
	}
	gen->num_herdoc = i;
}

void	free_struct(t_heredoc *hd, int nb_hd)
{
	int	i;

	i = -1;
	while (++i < nb_hd)
		free(&hd[i]);
	hd = NULL;
}
