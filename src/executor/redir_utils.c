# include "minishell.h"

void	mayor_sign(t_token *tok, t_general *gen)
{
	int	file;

	file = 0;
	if (tok->type == FLCH_DRCH || tok->type == D_FLCH_DRCH)
	{
		if (tok->type == FLCH_DRCH)
		{
			gen->dch = tok->str[0];
			file = ft_open_files(tok, 1);
		}
		if (tok->type == D_FLCH_DRCH)
		{
			gen->db_dch = tok->str[0];
			file = ft_open_files(tok, 2);
		}
		close(file);
	}
}

void	minor_sign(t_token *tok, t_general *gen)
{
	int	file;

	file = 0;
	if (tok->type == FLCH_IZQ || tok->type == D_FLCH_IZQ)
	{
		if (tok->type == FLCH_IZQ)
		{
			gen->izq = tok->str[0];
			file = ft_open_files(tok, 0);
		}
		if (tok->type == D_FLCH_IZQ)
		{
			gen->db_izq = tok->str[0];

		}
	}
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
