#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_general	t_general;

char*	get_path();
char*	create_full_path(char *dir, char *command);
int		check_command_access(char *full_path);
int		process_dirs(char **dirs, char *path, char *command);
int		is_command(char *command);

void handle_syntax_error(t_token *current_node);
void set_node_type(t_token *current_node);
void handle_redirection(t_token **current_node);
void categorize_arguments(t_token *tokens);
#endif