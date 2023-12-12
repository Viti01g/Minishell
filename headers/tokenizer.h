/* #ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

// Structs
typedef struct s_token
{
	int				words;
	int				type;
	char			**str;
	struct s_token	*next;
}	t_token;

// Tokens
void	split_token(char *input, t_token **tokens);
void	process_single_operator(char *input, t_token **tokens, int *i);
void	process_double_operator(char *input, t_token **tokens, int *i);
void	process_simple_operator(char *input, t_token **tokens, int *i, int *j);
void	free_tokens(t_token *tokens);

// Lists
t_token	*ft_lstnew_addback(t_token **token, char *str, int type);

// Utils
int		count_words(char **str);
void	print_tokens(t_token **tokens);

#endif */