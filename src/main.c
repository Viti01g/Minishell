/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:55:21 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/26 14:32:29 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *error)
{
	printf("\033[1;31mError: %s\033[0m\n", error);
	exit(EXIT_FAILURE);
}

int	cont_pipes(t_token **token)
{
	t_token	*aux;
	int		i;

	aux = *token;
	i = 0;
	while (aux != NULL)
	{
		if (aux->type == PIPE)
			i++;
		aux = aux->next;
	}
	return (i);
}

void	things_main(t_general *gen, char *view, bool *should_free_view)
{
	char	*expanded_view;

	expanded_view = expander(view);
	gen->num_pipes = split_token(expanded_view, &gen->token);
	remove_quotes_from_tokens(gen->token);
	if (categorize_arguments(gen->token))
	{
		free_tokens(gen->token);
		gen->token = NULL;
		*should_free_view = false;
		return ;
	}
	if (check_syntax(gen->token))
	{
		free_tokens(gen->token);
		gen->token = NULL;
		*should_free_view = false;
		return ;
	}
	gen->args = count_txt(gen->token->str);
	add_history(expanded_view);
	exec(gen);
	free_tokens(gen->token);
	gen->token = NULL;
	*should_free_view = false;
}

int	main(int argc, char **argv, char **env)
{
	char		*view;
	t_general	gen;
	bool		should_free_view;

	(void)argv;
	(void)argc;
	should_free_view = true;
	ft_disable_ctrl_c_printing_chars();
	init_vars(&gen, env, &view);
	while (1)
	{
		ft_signals();
		view = readline("\e[1;32mminishell$ \e[0m");
		if (!view)
			break ;
		if (ft_strlen(view) != 0 && check_quotes(view) == 1)
			things_main(&gen, view, &should_free_view);
		if (should_free_view)
			free(view);
		gen.token = NULL;
		should_free_view = true;
	}
	return (EXIT_SUCCESS);
}
