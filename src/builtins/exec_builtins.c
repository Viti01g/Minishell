#include "minishell.h"

void	ft_exec_builtins(t_general *gen)
{
	if (gen->token->str[0])
	{
		if (!ft_strcmp(gen->token->str[0], "cd"))
			cmd_cd(gen);
		else if (!ft_strcmp(gen->token->str[0], "env"))
			cmd_env(gen);
		else if (!ft_strcmp(gen->token->str[0], "pwd"))
			cmd_pwd(gen);
		else if (!ft_strcmp(gen->token->str[0], "exit"))
			cmd_exit(gen);
		else if (!ft_strcmp(gen->token->str[0], "echo"))
			cmd_echo(gen);
		else if (!ft_strcmp(gen->token->str[0], "unset"))
			cmd_unset(gen);
		else if (!ft_strcmp(gen->token->str[0], "export"))
			cmd_export(gen);
	}
	else
		return ;
}
