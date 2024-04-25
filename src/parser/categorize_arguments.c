#include "minishell.h"

void categorize_arguments(t_token *tokens)
{
	t_token *current_node;

	current_node = tokens;
	while (current_node != NULL)
	{
		if (strcmp(current_node->str[0], ">") == 0 || strcmp(current_node->str[0], ">>") == 0)
		{
			current_node = current_node->next;
			if (current_node == NULL)
			{
				printf("Syntax error\n");
				return ;
			}
			if (is_command(current_node->str[0]) || access(current_node->str[0], X_OK) == 0) // Check if the file is a command
				current_node->type = CMD;
			else
				current_node->type = OUTFILE;
		}
		else if (strcmp(current_node->str[0], "<") == 0)
		{
			current_node = current_node->next;
			if (current_node == NULL)
			{
				printf("Syntax error\n");
				return ;
			}
			if (is_command(current_node->str[0]) || access(current_node->str[0], X_OK) == 0) // Check if the file is a command
				current_node->type = CMD;
			else
				current_node->type = INFILE;
		}
		current_node = current_node->next;
	}
}
