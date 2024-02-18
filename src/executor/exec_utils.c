#include "minishell.h"

/* char	*find_name_com(char **paths, char **paths_aux, char *aux, char *argv)
{
	char	*str;
	char	*temp;

	str = NULL;
	temp = NULL;
	while (*paths != NULL)
	{
		if (access(argv, F_OK) == 0 && argv[0] == '/')
			return (free_matrix(paths_aux), argv);
		aux = ft_strjoin(*paths, "/");
		temp = ft_strjoin(aux, argv);
		if (access(temp, F_OK) == 0)
		{
			str = ft_substr(temp, 0, ft_strlen(temp));
			free(temp);
			free(aux);
			free_matrix(paths_aux);
			return (str);
		}
		paths++;
		free(temp);
		free(aux);
	}
	free_matrix(paths_aux);
	return (NULL);
} */

/* int	check_path(char *str, char **paths)
{
	int		n;
	char	*temp;
	char	*aux;

	n = 0;
	if (!paths)
		return (1);
	while (paths[n])
	{
		temp = ft_strjoin(paths[n], "/");
		aux = ft_strjoin(temp, str);
		if (access(aux, F_OK) == 0)
		{
			free(temp);
			free(aux);
			return (0);
		}
		free(temp);
		free(aux);
		n++;
	}
	return (1);
} */

/* char	*find_command(char *argv)
{
	char	*str;
	char	*aux;
	char	**paths_aux;
	char	**paths;

	paths = get_paths();
	aux = NULL;
	paths_aux = paths;
	if (argv[0] == '.' && (argv[1] == '.' || argv[1] == '/'))
		return (argv);
	if (access(argv, F_OK) == 0 && !check_if_builtin(argv)
		&& check_path(argv, paths))
		return (argv);
	if (paths == NULL)
		return (NULL);
	str = find_name_com(paths, paths_aux, aux, argv);
	return (str); 
}*/

int	check_if_builtin(char *str)
{
	if (ft_strcmp(str, "cd") == 0)
		return (1);
	else if (ft_strcmp(str, "echo") == 0)
		return (1);
	else if (ft_strcmp(str, "env") == 0)
		return (1);
	else if (ft_strcmp(str, "exit") == 0)
		return (1);
	else if (ft_strcmp(str, "export") == 0)
		return (1);
	else if (ft_strcmp(str, "pwd") == 0)
		return (1);
	else if (ft_strcmp(str, "unset") == 0)
		return (1);
	return (0);
}
