#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>             /* Para printf */
# include <readline/readline.h> 
# include <readline/history.h>
# include <signal.h>
# include <stdlib.h>			
# include <unistd.h>			
# include <sys/wait.h>		    
# include <signal.h>			
# include <sys/stat.h>		   
# include <fcntl.h>		    	
# include <dirent.h>			
# include <string.h>			
# include <errno.h>			   
# include <termios.h>		    
# include <curses.h>			
# include <limits.h>

// Our libraries

# include "../libft/libft.h"
# include "tokenizer.h"
# include "expander.h"

# define GREEN "\e[1;32m"
# define RESET "\e[0m"
# define RED "\e[1;91m"
# define CYAN "\e[1;36m"
# define YELLOW "\e[1;33m"
# define PURPLE "\e[1;35m"
# define BLUE "\e[1;34m"

// Macro Defines
# define EXIT_STATUS	128
# define TRUE  1
# define FALSE  0

# define READ 0
# define WRITE 1

enum	e_expt
{
	NEW_VALUE,
	CREATE,
	FAIL
};

enum	e_tok
{
	PIPE,
	FLCH_IZQ,		// <
	FLCH_DRCH,		// >
	D_FLCH_IZQ,		// <<
	D_FLCH_DRCH,	// >>
	CMD,
	DELM,
	INFILE,
	OUTFILE
};

enum	e_free
{
	F_NONE,
	F_SHELL,
	F_SUCCESS
};

enum	e_state
{
	ST_OK = 1,
	ST_PREPARED,
	ST_SIGINT,
	ST_READLINE,
	ST_ERROR,
	ST_SUCCESS
};

enum	e_error
{
	E_NONE,
	E_SIG,
	E_LEXER,
	E_MEM,
	E_PARSER,
	E_SYNTAX,
	E_EXECUTE,
	E_EXIT
};

enum	e_bash_error
{
	EB_NONE,
	EB_CATCHALL = 1,
	EB_MISUSE_BUILTINS = 2,
	EB_COMMAND_CANNOT_EXECUTE = 126,
	EB_COMMAND_NOT_FOUND = 127,
	EB_INVALID_ARG = 128,
	EB_EXIT_OUT_RANGE = 255
};

/* typedef struct s_pipe
{
	int				in;
	int				out;
}					t_pipe; */

typedef struct s_inf
{
	struct termios	termios;		//disable (ctrl + c) printing ^C
}	t_inf;	

int				g_signal_code;

typedef struct s_heredoc
{
	char	*delimi;
	int		fd[2];
}	t_heredoc;

typedef struct s_general
{
	int			args;
	int			num_pipes;
	char		**linea_entera;
	char		**env;
	char		*env_home;
	char		*env_path;
	char		*env_pwd;
	char		*env_oldpwd;
	char		*db_dch;
	char		*dch;
	char		*db_izq;
	char		*izq;
	char		*outfile;
	char		*infile;
	char		**delim;
	int			num_herdoc;
	int			fd[2];
	pid_t		id;
	t_heredoc	*heredc;
	t_token		*token;
	t_inf		*inf;
}	t_general;

t_general	g_gen;
int			g_signal_code;

void		ft_signals(void);
void		ft_signal_interrupt(void);
void		ft_signal_reset_prompt(int signal);
void		ft_disable_ctrl_c_printing_chars(void);
void		ft_signal_quit(void);
void		ft_sig_child(void);
void		sig_parent(void);
void		init_vars(t_general *gen, char **env);
char		**ft_cpy_env(char **env);
char		*ft_cpy_home(char **env);
char		*ft_cpy_path(char **env);
char		*ft_cpy_pwd(t_general **gen, char **env);
char		*ft_cpy_oldpwd(char **env);
void		cmd_env(t_general *gen);
void		cmd_exit(t_general *gen);
void		cmd_pwd(t_general *gen);
void		cmd_cd(t_general *gen);
void		cmd_export(t_general *gen);
void		cmd_unset(t_general *gen);
void		cmd_echo(t_general *gen);
int			split_token(char *input, t_token **tokens);
void		free_tokens(t_token *tokens);
void		ft_exec_builtins(t_general *gen);
int			count_txt(char **str);
void		ft_print_export(t_general *gen);
int			invalid_value(char **env);
void		free_matriz(char **str);
char		**ft_change_env(char **env, char *str, enum e_expt flag);
int			check_if_builtin(char *str);
t_token		*copy_no_pipe(t_token *token);
void		exec(t_general	*gen);
void		set_nodes(t_token **new_head, t_token **new_node, t_token **current_new);
int			cont_pipes(t_token **token);
int			check_if_builtin(char *str);
int			check_cmd_path(t_token *tmp, t_general *gen);
char		*buscar_var_env(char *var, char **env);
int			check_no_path(t_general **gen, t_token **toke, t_token **aux);
void		free_tokens_no_mtx(t_token *tokens);
void		check_redirs(t_token *tok, t_general *gen);
int			ft_open_files(t_token *tok, int type);
void		ft_file_type(t_token *tmp, t_general *gen);
void		heredoc(t_token *tok, t_general *gen);
int			ft_is_builtin(t_token *token, t_general *gen);
char		*find_in_path(t_token *toke, t_general *gen);
pid_t		ft_fork(void);
void		check_outfile(t_token *token, t_general *data, int fd_outf);
int			prueba_builtin(t_token *token, t_general *gen);
void		check_infile(t_token *token, t_general *gen, int fd_inf);
void		ft_executer(t_token *token, t_general *gen, int fd_inf, int fd_outf);
int			ft_exec_pipes(t_token *token, t_general *gen, int st_fd);
t_general	*reset_data(t_general *gen);
void		sig_ignore(void);
void		wait_child_process(t_token *token, t_general *gen);
void		heredoc(t_token *token, t_general *gen);
void		count_heredocs(t_token *token, t_general *gen);
void		free_struct(t_heredoc *hd, int nb_hd);
void		sig_heredoc(void);

// MORRALLA
void	ft_leaks(void);
void	ft_error(char *error);
int		ft_open_files2(char *str, int type);

// Other libraries need to go after the structs


#endif
