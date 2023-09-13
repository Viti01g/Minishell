#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>			    /* Para printf */
# include <stdlib.h>			/* Para malloc, free */
# include <unistd.h>			/* Para write, access, open, read, close, fork, exit, getcwd, chdir */
# include <sys/wait.h>		    /* Para wait, waitpid, wait3, wait4 */
# include <signal.h>			/* Para signal, sigaction, kill */
# include <sys/stat.h>		    /* Para stat, lstat, fstat */
# include <fcntl.h>		    	/* Para unlink, execve, dup, dup2, pipe */
# include <dirent.h>			/* Para opendir, readdir, closedir */
# include <string.h>			/* Para strerror */
# include <errno.h>			    /* Para perror */
# include <termios.h>		    /* Para tcsetattr, tcgetattr */
# include <curses.h>			/* Para tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs */
# include "../libft/libft.h"

# define CMD = 1;
# define PIPE = 2;
# define FLCH_IZQ = 3;
# define DBL_FLCH_IZQ = 4;
# define FLCH_DRCH = 5;
# define DBL_FLCH_DRCH = 6;

typedef struct s_token
{
    int     tipo;
    char    *str;
    t_token *new;
}   t_token;

#endif
