#include "minishell.h"

void	ft_per(char *var, char *s, int i)
{
	ft_putstr_fd(var, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(s);
	g_signal_code = i;
}

void	ft_put_msg(char *var, char *s)
{
	ft_putstr_fd(var, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	g_signal_code = 127;
}

void	ft_err_msg(char *s)
{
	ft_putendl_fd(s, 2);
	g_signal_code = 1;
}
