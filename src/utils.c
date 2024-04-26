/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:03:31 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/26 14:22:45 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_txt(char **str)
{
    int	i;

    if (str == NULL)
        return (0);
    i = 0;
    while (str[i] != NULL)
        i++;
    return (i);
}

void	free_matriz(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	free_tokens_no_mtx(t_token *tokens)
{
	t_token	*aux;

	aux = tokens;
	if (!tokens)
		return ;
	while (tokens && tokens->next)
	{
		if (tokens && tokens->next)
			aux = tokens->next;
		free(tokens);
		tokens = aux;
	}
	free(tokens);
}

t_general	*reset_data(t_general *gen)
{
	gen->delim = NULL;
	gen->outfile = NULL;
	gen->infile = NULL;
	return (gen);
}

void	ft_free_tokens(t_token *tokens)
{
	t_token	*aux;

	aux = tokens;
	if (!tokens)
		return ;
	while (tokens && tokens->next)
	{
		if (tokens->next)
			aux = tokens->next;
		free_matriz(tokens->str);
		free(tokens);
		tokens = aux;
	}
	free_matriz(tokens->str);
	free(tokens);
}
