#include "minishell.h"

static void	exec_cmds(t_token *tok, t_general *gen, int *fd)
{
	int	i;

	i = -1;
	while (tok && (++i <= gen->num_pipes))
	{
		if (ft_is_builtin(tok, gen) == 0)
			*fd = //funcion checkear builting

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
	printf("\n\n valor de la funcion: %d\n\n", i);
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
}