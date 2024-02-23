# include "minishell.h"

int	ft_open_files(t_token *tok, int type)
{
	int	fd;

	if (type == 0)
		fd = open(*tok->str, O_RDONLY, 0644);
	else if (type == 1)
		fd = open(*tok->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == 2)
		fd = open(*tok->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		signal_code = 1;
		exit(EXIT_FAILURE);
	}
	return (fd);
}
