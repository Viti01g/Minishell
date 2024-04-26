/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorize_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:02:06 by drubio-m          #+#    #+#             */
/*   Updated: 2024/04/26 15:03:32 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_syntax_error(t_token *current_node)
{
	if (current_node == NULL)
	{
		printf("syntax error near unexpected token '|' \n");
		g_signal_code = 1;
		return (1);
	}
	return (0);
}

void	set_node_type(t_token *current_node)
{
	if (is_command(current_node->str[0])
		|| access(current_node->str[0], X_OK) == 0)
		current_node->type = CMD;
	else
		current_node->type = OUTFILE;
}

int	handle_redirection(t_token **current_node)
{
	*current_node = (*current_node)->next;
	if (*current_node == NULL)
	{
		printf("syntax error near unexpected token '>' \n");
		g_signal_code = 1;
		return (1);
	}
	if (handle_syntax_error(*current_node))
		return (1);
	set_node_type(*current_node);
	return (0);
}

int	check_syntax(t_token *tokens)
{
    t_token	*current;

    current = tokens;
    while (current != NULL)
    {
        if ((current->type == PIPE || current->type == FLCH_IZQ
                || current->type == FLCH_DRCH
                || current->type == D_FLCH_DRCH)
            && (current->next == NULL))
        {
            printf("Error: syntax error near unexpected token `%s'\n",
                current->str[0]);
            g_signal_code = 1;
            return (1);
        }
        current = current->next;
    }
    return (0);
}
