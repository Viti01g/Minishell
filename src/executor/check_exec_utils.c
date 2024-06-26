/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:38:44 by vruiz-go          #+#    #+#             */
/*   Updated: 2024/04/25 22:06:36 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_infile(t_token *token, t_general *gen, int fd_inf)
{
	if (token->next && (gen->infile || gen->delim))
	{
		if (gen->db_izq && ft_strcmp(gen->db_izq, "<<") == 0)
			fd_inf = gen->heredc[gen->num_herdoc - 1].fd[READ];
		else if (gen->izq && ft_strcmp(gen->izq, "<") == 0)
			fd_inf = ft_open_files2(gen->infile, 0);
		if (dup2(fd_inf, STDIN_FILENO) == -1)
		{
			perror("Error duplicating file descriptor");
			g_signal_code = 1;
			exit(EXIT_FAILURE);
		}
		if (close(fd_inf) == -1)
		{
			perror("Error closing file descriptor");
			g_signal_code = 1;
			exit(EXIT_FAILURE);
		}
	}
	else if (fd_inf != STDIN_FILENO)
	{
		dup2(fd_inf, STDIN_FILENO);
		close(fd_inf);
	}
}

void	check_outfile(t_token *token, t_general *gen, int fd_outf)
{
	if (fd_outf != STDOUT_FILENO)
	{
		dup2(fd_outf, STDOUT_FILENO);
		close(fd_outf);
	}
	else if (token->next && (gen->outfile))
	{
		if (ft_strcmp(gen->dch, ">") == 0)
			fd_outf = ft_open_files2(gen->outfile, 1);
		else if (ft_strcmp(gen->db_dch, ">>") == 0)
			fd_outf = ft_open_files(token, 2);
		if (dup2(fd_outf, STDOUT_FILENO) == -1)
		{
			perror("Error duplicating file descriptor");
			g_signal_code = 1;
			exit(EXIT_FAILURE);
		}
		if (close(fd_outf) == -1)
		{
			perror("Error closing file descriptor");
			g_signal_code = 1;
			exit(EXIT_FAILURE);
		}
	}
}

int	ft_exec_pipes(t_token *token, t_general *gen, int st_fd)
{
	pipe(gen->fd);
	if (gen->fd < 0)
		exit (EXIT_FAILURE);
	ft_executer(token, gen, st_fd, gen->fd[WRITE]);
	close(gen->fd[WRITE]);
	if (st_fd != STDIN_FILENO)
		close(st_fd);
	return (gen->fd[READ]);
}

void	ft_executer(t_token *tok, t_general *gen, int fd_inf, int fd_outf)
{
	gen->id = ft_fork();
	if (gen->id == 0)
	{
		ft_sig_child();
		check_infile(tok, gen, fd_inf);
		check_outfile(tok, gen, fd_outf);
		if (tok->next && tok->next->type == CMD)
			close(gen->fd[READ]);
		if (!tok->path && tok->type == CMD)
		{
			ft_put_msg(gen->token->str[0], "command not found\n");
			exit (127);
		}
		if (execve(tok->path, tok->str, gen->env) == -1)
		{
			g_signal_code = 127;
			exit(1);
		}
	}
}
