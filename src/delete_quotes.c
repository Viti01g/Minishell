/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:58:24 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/26 10:58:25 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	p_d_quote(char *token, int *j, int *d_q_count, int s_q_count)
{
	(*d_q_count)++;
	if (s_q_count % 2 == 0)
		ft_memmove(&token[*j], &token[*j + 1], strlen(token) - *j);
	else
		(*j)++;
}

void	p_s_quote(char *token, int *j, int *s_q_count, int d_q_count)
{
	(*s_q_count)++;
	if (d_q_count % 2 == 0)
		ft_memmove(&token[*j], &token[*j + 1], strlen(token) - *j);
	else
		(*j)++;
}

void	process_token(char *current_token)
{
	int	j;
	int	d_q_count;
	int	s_q_count;

	j = 0;
	d_q_count = 0;
	s_q_count = 0;
	while (current_token[j] != '\0')
	{
		if (current_token[j] == '\"')
			p_d_quote(current_token, &j, &d_q_count, s_q_count);
		else if (current_token[j] == '\'')
			p_s_quote(current_token, &j, &s_q_count, d_q_count);
		else
			j++;
	}
}

void	process_node(t_token *current_node)
{
	int		i;
	char	*current_token;

	i = 0;
	while (current_node->str[i] != NULL)
	{
		current_token = current_node->str[i];
		process_token(current_token);
		i++;
	}
}

void	remove_quotes_from_tokens(t_token *tokens)
{
	t_token	*current_node;

	current_node = tokens;
	while (current_node != NULL)
	{
		process_node(current_node);
		current_node = current_node->next;
	}
}
