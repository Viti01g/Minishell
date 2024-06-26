/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:05:31 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/25 20:41:48 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

// Structs
typedef struct s_token
{
	int				words;
	int				type;	
	char			**str;	
	char			*path;
	struct s_token	*next;
}	t_token;

// Tokens
int		split_token(char *input, t_token **tokens);
void	process_single_operator(char *input, t_token **tokens, int *i);
void	process_double_operator(char *input, t_token **tokens, int *i);
void	process_simple_operator(char *input, t_token **tokens, int *i, int *j);
void	free_tokens(t_token *tokens);

// Quotes
int		process_quotes(char *str, int i, char del);
int		change_quote_state(int quote);
void	until_double(char *input, int *i, int *double_flag);
void	until_single(char *input, int *i, int *single_flag);
int		check_quotes(char *input);
int		skip_spaces(char *str, int i);
int		is_whitespace(char c);

// Quote Removal
void	remove_quotes_from_tokens(t_token *tokens);
void	process_node(t_token *current_node);
void	process_token(char *current_token);
void	p_s_quote(char *token, int *j, int *s_q_count, int d_q_count);
void	p_d_quote(char *token, int *j, int *d_q_count, int s_q_count);

// Lists
t_token	*ft_lstnew_addback(t_token **token, char *str, int type);

// Utils
int		count_words(char **str);
void	print_tokens(t_token **tokens);

#endif
