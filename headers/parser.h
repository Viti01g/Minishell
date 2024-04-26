#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_general	t_general;

char*	get_path();
char*	create_full_path(char *dir, char *command);
int		check_command_access(char *full_path);
int		process_dirs(char **dirs, char *path, char *command);
int		is_command(char *command);


void	set_node_type(t_token *current_node);
int	handle_syntax_error(t_token *current_node);
int	categorize_arguments(t_token *tokens);
int	handle_redirection(t_token **current_node);
int check_syntax(t_token *tokens);

int check_redirection(t_token *current_node);
int check_pipe(t_token *current_node);
int handle_pipe(t_token **current_node, t_token *tokens);
int categorize_arguments(t_token *tokens);

#endif