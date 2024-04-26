/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:56:19 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/26 10:50:16 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(void)
{
	char	*path;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	path = ft_strdup(path);
	return (path);
}

char	*create_full_path(char *dir, char *command)
{
    char	*full_path;
    char	*temp;

    if (dir == NULL || command == NULL)
        return (NULL);
    full_path = malloc(strlen(dir) + 1 + strlen(command) + 1);
    if (full_path == NULL)
        return (NULL);
    ft_strcpy(full_path, dir);
    temp = full_path;
    full_path = ft_strjoin(full_path, "/");
    free(temp);
    temp = full_path;
    full_path = ft_strjoin(full_path, command);
    free(temp);
    return (full_path);
}

int	check_command_access(char *full_path)
{
	if (access(full_path, X_OK) == 0)
		return (1);
	return (0);
}

int	process_dirs(char **dirs, char *path, char *command)
{
	char	*full_path;
	int		i;

	i = -1;
	while (dirs[++i] != NULL)
	{
		full_path = create_full_path(dirs[i], command);
		if (full_path == NULL)
		{
			free(path);
			free(dirs);
			return (0);
		}
		if (check_command_access(full_path))
		{
			free(full_path);
			free(path);
			free(dirs);
			return (1);
		}
		free(full_path);
	}
	free(path);
	free(dirs);
	return (0);
}

int	is_command(char *command)
{
	char	*path;
	char	**dirs;

	path = get_path();
	if (path == NULL)
		return (0);
	dirs = ft_split(path, ':');
	if (dirs == NULL)
	{
		free(path);
		return (0);
	}
	return (process_dirs(dirs, path, command));
}
