#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* expand_variables(char* input)
{
    char* output = malloc(strlen(input) * 2); // Allocate memory for output
    char* var_start = NULL;
    int i, j = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '$') { // Start of variable
            var_start = &input[i+1];
        } else if (var_start) {
            if (input[i] == ' ' || input[i] == '\0') { // End of variable
                char var_name[256];
                strncpy(var_name, var_start, &input[i] - var_start);
                var_name[&input[i] - var_start] = '\0';
                char* var_value = getenv(var_name);
                if (var_value) {
                    strcpy(&output[j], var_value);
                    j += strlen(var_value);
                }
                var_start = NULL;
                if (input[i] != '\0') {
                    output[j++] = input[i];
                }
            }
        } else {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
    return output;
}

int main()
{
    char* input = "echo $HOME";
    char* output = expand_variables(input);
    printf("%s\n", output);
    free(output);
    return 0;
}

/* int	main(void)
{
	char	*input;
	t_token	*tokens;

	//atexit(ft_leaks);
	tokens = NULL;
//	printf("%p\n", input);
//	printf("%s\n", input);
	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		if (!input || !ft_strcmp(input, "exit"))
			break ;
		check_quotes(input);
		split_token(input, &tokens);
		free(input);
		free_tokens(tokens);
		tokens = NULL;
	}
	return (0);
} */
