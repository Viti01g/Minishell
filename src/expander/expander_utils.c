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

// *UTIL PARA IMPRIMIR VARS
/* void print_env_var(t_general *gen, char *var)
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
} */

char *create_and_fill_array(char *input)
{
    char *result;
    int  i[2]; 
    int in_quotes;

    result = malloc(sizeof(char) * (calculate_expanded_str(input) + 1));
    i[0] = 0;
    i[1] = 0;
    in_quotes = 0;
    while(input[i[0]])
    {
        if (input[i[0]] == '\'')
            in_quotes = !in_quotes;
        handle_variable_expansion(input, i, result, &in_quotes);
    }
    result[i[1]] = '\0';
    free(input);
	//printf("Este es tu output:\n %s\n", result);
    return result;
}

void handle_variable_expansion(char *input, int *i, char *result, int *in_quotes)
{
	char *var;
	char *expanded_var;
	int var_start;

    if (input[i[0]] == '$' && !(*in_quotes) && (input[i[0] + 1] == '_' || ft_isalpha(input[i[0] + 1])))
    {
        var_start = i[0];
        skip_until_space_or_dollar(input, &i[0]);
        var = ft_substr(input, var_start + 1, i[0] - var_start - 1);
        expanded_var = getenv(var);
        if (expanded_var != NULL)
        {
            ft_strcpy(&result[i[1]], expanded_var);
            i[1] += ft_strlen(expanded_var);
        }
        free(var);
    }
    else
        result[i[1]++] = input[i[0]++];
}
