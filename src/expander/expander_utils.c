#include "minishell.h"

void	*ft_realloc(void *ptr, size_t len, size_t new_size)
{
	void	*new;

	if (new_size == 0)
		return (NULL);
	new = malloc(new_size);
	if (!new)
		return (NULL);
	if (ptr != NULL)
	{
		ft_memcpy(new, ptr, len);
		free(ptr);
	}
	return (new);
}

void print_env_var(t_general *gen, char *var)
{
    char **env = gen->env;
    char *subst;
	int i;

	i = 0;
	while (env[i] && ft_strncmp(var, env[i], ft_strlen(var)))
		++i;
	if (!env[i])
	{
		printf("Variable %s not found in environment\n", var);
		return ;
	}
	subst = strchr(env[i], '=');
	printf("%s=%s\n", var, subst + 1);
    while (*env)
    {
        subst = ft_strchr(*env, '=');
        if (subst)
        {
            subst = ft_substr(*env, 0, ft_strlen(*env) - ft_strlen(subst) + 1);
            if (ft_strcmp(var, subst) == 0)
            {
                printf("%s\n", *env + ft_strlen(subst));
                free(subst);
                return;
            }
            free(subst);
        }
        env++;
    }
    //printf("Variable %s not found in environment\n", var);
}

/* char *create_and_fill_array(char *input)
{
	char *result;
	int  i;
	int in_quotes;

	result = malloc(sizeof(char) * (calculate_expanded_str(input) + 1));
	i = -1;
	in_quotes = 0;
	while(input[++i])
	{
		if (input[i] == '\'')
			in_quotes = !in_quotes;
		if (input[i] == '$' && !in_quotes)
		{

		}
	}
} */

char *create_and_fill_array(char *input)
{
    char *result;
    int  i[2]; // i[0] for input index, i[1] for result index
    int in_quotes;

    result = malloc(sizeof(char) * (calculate_expanded_str(input) + 1));
    i[0] = 0;
    i[1] = 0;
    in_quotes = 0;
    while(input[i[0]])
    {
        if (input[i[0]] == '\'')
            in_quotes = !in_quotes;
        if (input[i[0]] == '$' && !in_quotes && (input[i[0] + 1] == '_' || ft_isalpha(input[i[0] + 1])))
        {
            int var_start = i[0];
            skip_until_space_or_dollar(input, &i[0]);
            char *var = ft_substr(input, var_start + 1, i[0] - var_start - 1);
            char *expanded_var = getenv(var);
            if (expanded_var != NULL) {
                ft_strcpy(&result[i[1]], expanded_var);
                i[1] += ft_strlen(expanded_var);
            }
            free(var);
        }
        else
            result[i[1]++] = input[i[0]++];
    }
    result[i[1]] = '\0'; // null-terminate the result string
	printf("Result: %s\n", result);
    return result;
}


