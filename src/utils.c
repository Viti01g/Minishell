#include "minishell.h"

static int	count_txt(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	type_args(t_token **tok)
{
	t_token	**prueba;
	int		i;

	prueba = tok;
	while (prueba)
	{
		i = 0;
		if ((*prueba)->str[i] == '|')
			(*tok)->type = PIPE;
		else if ((*prueba)->str[i] == '<' && (*prueba)->str[i + 1] == '<')
			(*tok)->type = D_FLCH_IZQ;
		else if ((*prueba)->str[i] == '>' && (*prueba)->str[i + 1] == '>')
			(*tok)->type = D_FLCH_DRCH;
		else if ((*prueba)->str[i] == '<')
			(*tok)->type = FLCH_IZQ;
		else if ((*prueba)->str[i] == '>')
			(*tok)->type = FLCH_DRCH;
		else
		{
			(*tok)->words = count_txt((*tok)->str);
			(*tok)->type = TXT;
		}
		(*prueba) = (*prueba)->next;
	}
	return ;
}
