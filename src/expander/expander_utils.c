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
	while (*env && ft_strncmp(var, env[i], ft_strlen(var)))
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
    printf("Variable %s not found in environment\n", var);
}
