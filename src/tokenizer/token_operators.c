#include "minishell.h"

void	process_simple_operator(char *input, t_token **tokens, int *i, int *j)
{
	char	*fragment;

	fragment = ft_substr(input, *j, *i - *j);
	ft_lstnew_addback(tokens, fragment, TXT);
	free(fragment);
}

void	process_double_operator(char *input, t_token **tokens, int *i)
{
	char	*fragment;

	fragment = ft_substr(input, *i, 2);
	if (input[*i] == '>')
		ft_lstnew_addback(tokens, fragment, D_FLCH_DRCH);
	else if (input[*i] == '<')
		ft_lstnew_addback(tokens, fragment, D_FLCH_IZQ);
	(*i)++;
	free(fragment);
}

void	process_single_operator(char *input, t_token **tokens, int *i)
{
	char	*fragment;

	fragment = ft_substr(input, *i, 1);
	if (input[*i] == '>')
		ft_lstnew_addback(tokens, fragment, FLCH_DRCH);
	else if (input[*i] == '<')
		ft_lstnew_addback(tokens, fragment, FLCH_IZQ);
	else if (input[*i] == '|')
		ft_lstnew_addback(tokens, fragment, PIPE);
	free(fragment);
}