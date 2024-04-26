/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:55:21 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/26 10:56:05 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *error)
{
	printf("\033[1;31mError: %s\033[0m\n", error);
	exit(EXIT_FAILURE);
}

void	things_main(t_general *gen, char *view)
{
	ft_signals();
	view = readline("\e[1;32mminishell$ \e[0m");
	if (!view)
	{
		printf("Exit\n");
		exit(EXIT_SUCCESS);
	}
	check_quotes(view);
	view = expander(view);
	gen->num_pipes = split_token(view, &gen->token);
	remove_quotes_from_tokens(gen->token);
	categorize_arguments(gen->token);
	if (ft_strlen(view) != 0)
	{
		gen->args = count_txt(gen->token->str);
		add_history(view);
		exec(gen);
		ft_free_tokens(gen->token);
		gen->token = gen->token->next;
	}
	free(view);
	gen->token = NULL;
}

int	main(int argc, char **argv, char **env)
{
	char		*view;
	t_general	gen;

	(void)argv;
	(void)argc;
	ft_disable_ctrl_c_printing_chars();
	init_vars(&gen, env, &view);
	while (1)
	{
		things_main(&gen, view);
	}
	return (EXIT_SUCCESS);
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
