#include "minishell.h"

void	signal_input(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_sign(void)
{
	signal(SIGINT, &signal_input);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_parent(void)
{
	signal(SIGINT, &signal_input);
	signal(SIGQUIT, SIG_IGN);
}
