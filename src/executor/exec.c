#include "minishell.h"

void	exec(t_general	*gen)
{
	t_token	*first;
	t_token	*aux;

	aux = copy_no_pipe(gen->token);
	first = aux;
	if (check_cmd_path(aux, gen) != 0)
	{
		free_tokens_no_mtx(aux);
	}
}