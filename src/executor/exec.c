#include "minishell.h"

/* int	cont_nodes(t_general *gen)
{
	int	i;

	i = 0;

} */

void	exec(t_general	*gen)
{
	//t_general	*first;
	t_general	*aux;
	int			n_pipe;

	aux = gen;
	printf("se\n");
	aux->token = copy_no_pipe(gen->token);
	sleep(2);
	n_pipe = cont_pipes(&gen->token);
	//first = aux;
	
}