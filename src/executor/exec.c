#include "minishell.h"

void	exec(t_general	*gen)
{
	t_token	*first;
	t_token	*aux;

	aux = copy_no_pipe(gen->token);
	first = aux;
	int i = check_cmd_path(aux, gen);
	printf("\n\n valor de la funcion: %d\n\n", i);
	if (i != 0)
	{
		free_tokens_no_mtx(aux);
		return ;
	}
	check_redirs(aux, gen);
	if (gen->delim)
		heredoc(aux, gen); // empezar heredoc.
}