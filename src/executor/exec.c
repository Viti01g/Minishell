/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:22:07 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/24 18:59:21 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_built_pips(t_token *token, t_general *gen)
{
	int	fd[2];

	pipe(fd);
	if (fd < 0)
		exit(EXIT_FAILURE);
	if (!ft_fork())
	{
		close(fd[READ]);
		if (gen->outfile != NULL)
			check_outfile(token, gen, STDOUT_FILENO);
		else
			dup2(fd[WRITE], STDOUT_FILENO);
		close(fd[WRITE]);
		ft_exec_builtins(gen);
		exit(0);
	}
	close(fd[WRITE]);
	return (fd[READ]);
}

int	prueba_builtin(t_token *token, t_general *gen)
{
	while (token)
	{
		if ((!token->next) && gen->outfile == NULL)
		{
			ft_exec_builtins(gen);
			return (STDIN_FILENO);
		}
		else
			return (ft_built_pips(token, gen));
		token = token->next;
	}
	return (STDIN_FILENO);
}

static pid_t	ft_single(t_token *token, t_general *gen, int fdin, int fdout)
{
	pid_t	pd;

	pd = fork();
	if (pd == -1)
		ft_error("fork() error");
	if (pd == 0)
	{
		check_infile(token, gen, fdin);
		check_outfile(token, gen, fdout);
		check_some_exec(token, gen);
		if (fdin > 0)
		{
			dup2(fdin, STDIN_FILENO);
			close(fdin);
		}
		if (fdout > 1)
			dup2(fdout, STDOUT_FILENO);
		if (execve(token->path, token->str, gen->env) == -1)
			exit(1);
	}
	close(fdin);
	return (pd);
}

// ****** REVISAR EL FREE COMENTADO
static void	exec_cmds(t_token *tok, t_general *gen, int fd)
{
	int	i;

	i = -1;
	while (tok && (++i <= gen->num_pipes))
	{
		if (ft_is_builtin(tok, gen) == 0)
			fd = prueba_builtin(tok, gen);
		else if (i == gen->num_pipes && gen->num_pipes == 0)
			ft_executer(tok, gen, fd, STDOUT_FILENO);
		else if (i == gen->num_pipes)
			fd = ft_single(tok, gen, fd, STDOUT_FILENO);
		else
			fd = ft_exec_pipes(tok, gen, fd);
		free(tok->path);
		tok = tok->next;
	}
}

void	exec(t_general	*gen)
{
	t_token	*first;
	t_token	*aux;
	int		fd;

	gen->token->path = NULL;
	aux = copy_no_pipe(gen->token);
	first = aux;
	if (check_cmd_path(aux, gen) != 0)
	{
		free_tokens_no_mtx(aux);
		return ;
	}
	check_redirs(aux, gen);
	if (gen->delim && *gen->delim)
		heredoc(aux, gen);
	aux = first;
	fd = STDIN_FILENO;
	exec_cmds(aux, gen, fd);
	gen = reset_data(gen);
	free_tokens_no_mtx(first);
	if (fd != STDIN_FILENO)
		close(fd);
	wait_child_process(gen->token, gen);
}
