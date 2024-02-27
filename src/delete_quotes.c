#include "minishell.h"

void p_d_quote(char *current_token, int *j, int *double_quote_count, int single_quote_count)
{
    (*double_quote_count)++;
    if (single_quote_count % 2 == 0)
        ft_memmove(&current_token[*j], &current_token[*j + 1], strlen(current_token) - *j);
    else
        (*j)++;
}

void p_s_quote(char *current_token, int *j, int *single_quote_count, int double_quote_count)
{
    (*single_quote_count)++;
    if (double_quote_count % 2 == 0)
        ft_memmove(&current_token[*j], &current_token[*j + 1], strlen(current_token) - *j);
    else
        (*j)++;
}

void process_token(char *current_token)
{
    int j;
    int double_quote_count;
    int single_quote_count;

    j = 0;
    double_quote_count = 0;
    single_quote_count = 0;
    while (current_token[j] != '\0')
    {
        if (current_token[j] == '\"')
            p_d_quote(current_token, &j, &double_quote_count, single_quote_count);
        else if (current_token[j] == '\'')
            p_s_quote(current_token, &j, &single_quote_count, double_quote_count);
        else
            j++;
    }
}

void process_node(t_token *current_node)
{
    int i;
    char *current_token;

    i = 0;
    while (current_node->str[i] != NULL)
    {
        current_token = current_node->str[i];
        process_token(current_token);
        i++;
    }
}

void remove_quotes_from_tokens(t_token *tokens)
{
    t_token *current_node;

    current_node = tokens;
    while (current_node != NULL)
    {
        process_node(current_node);
        current_node = current_node->next;
    }
}
