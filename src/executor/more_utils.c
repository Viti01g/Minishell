# include "minishell.h"

void	mayor_sign(t_token *tok, t_general *gen)
{
	int	file;

	file = 0;
}

int	ft_is_redir(int type)
{
	if (type >= 1 && type <= 4)
		return (1);
	return (0);
}

void	check_redirs(t_token *tok, t_general *gen)
{
	t_token	*aux;

	aux = tok;
	while (aux)
	{
		if (!ft_is_redir(aux->type))
		{

		}
	}
}
