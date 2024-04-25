/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorize_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:03:55 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/25 19:03:58 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void categorize_arguments(t_token *tokens)
{
	t_token *cur;

	cur = tokens;
	while (cur != NULL)
	{
		if (strcmp(cur->str[0], ">") == 0 || strcmp(cur->str[0], ">>") == 0)
		{
			cur = cur->next;
			if (cur == NULL)
			{
				printf("Syntax error\n");
				return ;
			}
			if (is_command(cur->str[0]) || access(cur->str[0], X_OK) == 0)
				cur->type = CMD;
			else
				cur->type = OUTFILE;
		}
		else if (strcmp(cur->str[0], "<") == 0)
		{
			cur = cur->next;
			if (cur == NULL)
			{
				printf("Syntax error\n");
				return ;
			}
			if (is_command(cur->str[0]) || access(cur->str[0], X_OK) == 0)
				cur->type = CMD;
			else
				cur->type = INFILE;
		}
		cur = cur->next;
	}
}
