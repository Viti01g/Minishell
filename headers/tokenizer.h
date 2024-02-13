#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

// Structs
typedef struct s_token
{
	int				words;  //"2"  
	int				type;	//"cmd"		"cmd"
	char			**str;  //"str[0]: ls; str[1]: -la"   "echo hola"
	struct s_token	*next;
}	t_token;

// Tokens
void	split_token(char *input, t_token **tokens);
void	process_single_operator(char *input, t_token **tokens, int *i);
void	process_double_operator(char *input, t_token **tokens, int *i);
void	process_simple_operator(char *input, t_token **tokens, int *i, int *j);
void	free_tokens(t_token *tokens);

// Quotes
int		process_quotes(char *str, int i, char del);
int		change_quote_state(int quote);
void	until_double(char *input, int *i, int *double_flag);
void	until_single(char *input, int *i, int *single_flag);
void	check_quotes(char *input);
int		skip_spaces(char *str, int i);
int		is_whitespace(char c);

// Lists
t_token	*ft_lstnew_addback(t_token **token, char *str, int type);

// Utils
int		count_words(char **str);
void	print_tokens(t_token **tokens);

#endif
