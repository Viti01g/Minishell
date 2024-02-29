# include "minishell.h"

void	check_infile(t_token *token, t_general *gen, int fd_inf)
{
	if (token->next && (gen->infile || gen->delim))
	{
		printf("si entra en el if de check infile\n");
		if (gen->db_izq && ft_strcmp(gen->db_izq, "<<") == 0)
			fd_inf = gen->heredc[gen->num_herdoc - 1].fd[READ];
		else if (gen->izq && ft_strcmp(gen->izq, "<") == 0)
			fd_inf = ft_open_files(token, 0);
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
		if (ft_strcmp(gen->dch, ">") == 0){
			fd_outf = ft_open_files2(gen->outfile, 1);
		}
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
	//printf("fd read es %d\n", gen->fd[READ]);
	return (gen->fd[READ]);
}

void	ft_executer(t_token *token, t_general *gen, int fd_inf, int fd_outf)
{
	gen->id = ft_fork();
	if (gen->id == 0)
	{
		ft_sig_child();
		check_infile(token, gen, fd_inf);
		check_outfile(token, gen, fd_outf);
		if (token->next && token->next->type == CMD)
			close(gen->fd[READ]);
		if (!token->path && token->type == CMD)
			;//exec_exit_error(2, token->str[0]);
		if (execve(token->path, token->str, gen->env) == -1)
		{
			printf("entro\n");
			//free_view(gen);
			g_signal_code = 127;
			exit(1);
		}
		//free_view(gen);
	}
}
