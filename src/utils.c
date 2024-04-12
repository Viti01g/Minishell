#include "minishell.h"

int	count_txt(char **str)
{
	int	i;

	i = 0;
	if (str[i] == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	free_matriz(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	free_tokens_no_mtx(t_token *tokens)
{
	t_token	*aux;

	aux = tokens;
	if (!tokens)
		return ;
	while (tokens && tokens->next)
	{
		if (tokens && tokens->next)
			aux = tokens->next;
		free(tokens);
		tokens = aux;
	}
	free(tokens);
}

t_general	*reset_data(t_general *gen)
{
	gen->delim = NULL;
	gen->outfile = NULL;
	gen->infile = NULL;
	return (gen);
}

void	ft_free_tokens(t_token *tokens)
{
	t_token	*aux;

	aux = tokens;
	if (!tokens)
		return ;
	while (tokens && tokens->next)
	{
		if (tokens->next)
			aux = tokens->next;
		free_matriz(tokens->str);
		free(tokens);
		tokens = aux;
	}
	free_matriz(tokens->str);
	free(tokens);
}

/* void	free_view(t_general *gen)
{
	t_token	*aux;

	aux = gen->token;
	free(gen->);
		gen->line = NULL;
} */

/* void	type_args(t_token **tok)
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
}*/
