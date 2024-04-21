#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_general	t_general;

char*	get_path();
char*	create_full_path(char *dir, char *command);
int		check_command_access(char *full_path);
int		is_command(char *command);

#endif