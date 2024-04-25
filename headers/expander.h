/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:05:38 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/24 17:05:39 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"

typedef struct s_general	t_general;

// Expander
char	*expander(char *input);
char	*create_and_fill_array(char *input);
char	*aux_calculate(char *input, int *i);
int		calculate_expanded_str(char *input);
void	handle_var_expand(char *input, int *i, char *result, int *in_quotes);

// Expander Utils
void	*ft_realloc(void *ptr, size_t len, size_t new_size);
void	print_env_var(t_general *gen, char *var);
void	skip_until_space(char *input, int *i);
void	skip_until_space_or_dollar(char *input, int *i);
int		check_valid_var(char *str, int start, int len);

#endif