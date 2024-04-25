/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:01:52 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/25 22:03:07 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_general	t_general;

char	*get_path(void);
char	*create_full_path(char *dir, char *command);
int		check_command_access(char *full_path);
int		process_dirs(char **dirs, char *path, char *command);
int		is_command(char *command);

void	categorize_arguments(t_token *tokens);
#endif