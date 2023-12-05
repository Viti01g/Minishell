#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

void	split_token(char *input, t_token **tokens);
void	print_tokens(t_token **tokens);
void	process_single_operator(char *input, t_token **tokens, int *i);
void	process_double_operator(char *input, t_token **tokens, int *i);
void	process_simple_operator(char *input, t_token **tokens, int *i, int *j);
void	free_tokens(t_token *tokens);





// Listas
t_token	*ft_lstnew_addback(t_token **token, char *str);

#endif