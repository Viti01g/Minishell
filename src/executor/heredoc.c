# include "minishell.h"

void	hd_delims(t_token *token, t_heredoc *hd)
{
	int		i;
	t_token	*aux;

	i = 0;
	aux = token;
	while (aux && aux->next)
	{
		if (aux->type == D_FLCH_IZQ)
		{
			aux = aux->next;
			hd[i].delimi = *aux->str;
			pipe(hd[i++].fd);
		}
		aux = aux->next;
	}
}

void	put_content_hd(int index, t_heredoc *hd)
{
	char	*line;
	char	*line_aux;

	line = readline("> ");
	while (line)
	{
		if (ft_strncmp(line, hd[index].delimi, ft_strlen(line) + 1) == 0)
			break ;
		line_aux = expander(line);
		line = ft_strtrim(line_aux, "\"");
		free(line_aux);
		ft_putendl_fd(line, hd[index].fd[WRITE]);
		free (line);
		line = readline("> ");
	}
	free (line);
	close(hd[index].fd[WRITE]);
	close(hd[index].fd[READ]);
}

void	do_here_doc(t_general *gen, pid_t pid)
{
	int	i;

	if (pid == 0)
	{
		sig_heredoc();
		i = -1;
		while (++i < gen->num_herdoc)
			put_content_hd(i, gen->heredc);

		while (++i < gen->num_herdoc)
			free_struct(gen->heredc, i);
		exit(1);
	}
	else if (pid > 0)
	{
		i = -1;
		while (++i < gen->num_herdoc)
			close(gen->heredc[i].fd[WRITE]);
	}
}

void	heredoc(t_token *token, t_general *gen)
{
	pid_t	pid;
	int		status;
	t_token	*tmp;

	tmp = token;
	count_heredocs(tmp, gen);
	gen->heredc = ft_calloc(sizeof(t_heredoc), gen->num_herdoc);
	hd_delims(tmp, gen->heredc);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		exit(0);
	do_here_doc(gen, pid);
	waitpid(pid, &status, 0);
}
