#ifndef EXPANDER_H
# define EXPANDER_H

char *expander(char *input);
void skip_until_space(char *input, int *i);
int check_valid_var(char *str, int start, int len);


#endif