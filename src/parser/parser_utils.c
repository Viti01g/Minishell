/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:30:21 by drubio-m          #+#    #+#             */
/*   Updated: 2024/04/26 14:23:08 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_redirection(t_token *current_node)
{
    return strcmp(current_node->str[0], ">") == 0
        || strcmp(current_node->str[0], ">>") == 0
        || strcmp(current_node->str[0], "<") == 0;
}

int check_pipe(t_token *current_node)
{
    return strcmp(current_node->str[0], "|") == 0;
}

int handle_pipe(t_token **current_node, t_token *tokens)
{
    *current_node = (*current_node)->next;
    if (*current_node == NULL || (*current_node)->str[0] == NULL)
	{
		printf("syntax error near unexpected token '|' \n");
		g_signal_code = 1;
        free_tokens(tokens);
        return (1);
    }
    if (check_redirection(*current_node))
	{
		printf("syntax error near unexpected token '|' \n");
		g_signal_code = 1;
        free_tokens(tokens);
        return (1);
    }
    return (0);
}

int categorize_arguments(t_token *tokens)
{
    t_token *current_node;
	
    current_node = tokens;
    while (current_node != NULL)
    {
        if (check_redirection(current_node))
		{
            if (handle_redirection(&current_node))
                return 1;
        }
        else if (check_pipe(current_node))
		{
            if (handle_pipe(&current_node, tokens))
                return 1;
        }
        current_node = current_node->next;
    }
    return (0);
}
