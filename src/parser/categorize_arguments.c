#include "minishell.h"

void handle_syntax_error(t_token *current_node)
{
    if (current_node == NULL)
    {
        printf("Syntax error\n");
        exit(1);
    }
}

void set_node_type(t_token *current_node)
{
    if (is_command(current_node->str[0]) || access(current_node->str[0], X_OK) == 0)
        current_node->type = CMD;
    else
        current_node->type = OUTFILE;
}

void handle_redirection(t_token **current_node)
{
    *current_node = (*current_node)->next;
    handle_syntax_error(*current_node);
    set_node_type(*current_node);
}

void categorize_arguments(t_token *tokens)
{
    t_token *current_node;

    current_node = tokens;
    while (current_node != NULL)
    {
        if (strcmp(current_node->str[0], ">") == 0 || strcmp(current_node->str[0], ">>") == 0)
        {
            handle_redirection(&current_node);
        }
        else if (strcmp(current_node->str[0], "<") == 0)
        {
            handle_redirection(&current_node);
            current_node->type = INFILE;
        }
        current_node = current_node->next;
    }
}
