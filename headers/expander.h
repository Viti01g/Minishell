#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"
typedef struct s_general t_general;

// Expander
char *expander(char *input);
void skip_until_space(char *input, int *i);
int check_valid_var(char *str, int start, int len);
void skip_until_space_or_dollar(char *input, int *i);
char *create_and_fill_array(char *input);




// Expander Utils
void	*ft_realloc(void *ptr, size_t len, size_t new_size);
void print_env_var(t_general *gen, char *var);
int calculate_expanded_str(char *input);

#endif