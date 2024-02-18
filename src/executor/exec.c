#include "minishell.h"

/* int	cont_nodes(t_general *gen)
{
	int	i;

	i = 0;

} */

void	exec(t_general	*gen)
{
	t_token	*first;
	t_token	*aux;

	aux = copy_no_pipe(gen->token);
	first = aux;
	
}