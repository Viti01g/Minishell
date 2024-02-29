#include "minishell.h"

int	ft_built_pips(t_token *token, t_general *gen)
{
	int	fd[2];

	pipe(fd);
	if (fd < 0)
		exit(EXIT_FAILURE);
	if (!ft_fork())
	{
		close(fd[READ]);
		if (gen->outfile != NULL)
			check_outfile(token, gen, STDOUT_FILENO);
		else
			dup2(fd[WRITE], STDOUT_FILENO);
		close(fd[WRITE]);
		ft_exec_builtins(gen, token, STDOUT_FILENO);
		exit(0);
	}
	close(fd[WRITE]);
	return (fd[READ]);
}

int	prueba_builtin(t_token *token, t_general *gen)
{
	while (token)
	{
		if ((!token->next) && gen->outfile == NULL)
		{
			ft_exec_builtins(gen, token, STDOUT_FILENO);
			return (STDIN_FILENO);
		}
		else
			return (ft_built_pips(token, gen));
		token = token->next;
	}
	return (STDIN_FILENO);
}

// !MIRAR EL FREE COMENTADO
static void	exec_cmds(t_token *tok, t_general *gen, int *fd)
{
	int	i;

	i = -1;
	while (tok && (++i <= gen->num_pipes))
	{
		if (ft_is_builtin(tok, gen) == 0)
			*fd = prueba_builtin(tok, gen);
		else if (i == gen->num_pipes)
			ft_executer(tok, gen, *fd, STDOUT_FILENO);
		else
			ft_exec_pipes(tok, gen, *fd);
//		free(tok->path);
		tok = tok->next;
	}
}

void	exec(t_general	*gen)
{
	t_token	*first;
	t_token	*aux;
	int		fd;

	aux = copy_no_pipe(gen->token);
	first = aux;
	int i = check_cmd_path(aux, gen); // Cambiar cuando diego meta los tipo inf, out, cmd.
	if (i != 0)
	{
		free_tokens_no_mtx(aux);
		return ;
	}
	check_redirs(aux, gen);
	/* if (gen->delim)
		heredoc(aux, gen); */ // empezar heredoc.
	fd = STDIN_FILENO;
	exec_cmds(aux, gen, &fd);
	gen = reset_data(gen);
	if (fd != STDIN_FILENO)
		close(fd);
	
}
