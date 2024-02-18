
#include "minishell.h"

void	ft_error(char *error)
{
	printf("\033[1;31mError: %s\033[0m\n", error);
	exit(EXIT_FAILURE);
}

void	view_prompt(void)
{
	write(1, GREEN, ft_strlen(GREEN));
	write(1, "minishell$ ", strlen("minishell$ "));
	write(1, RESET, ft_strlen(RESET));
}


int main(int argc, char **argv, char **env)
{
	char		*view;
	t_general	gen;

	(void)argv;
	gen.token = NULL;
	ft_disable_ctrl_c_printing_chars();
	view = "a";
	init_vars(&gen, env);
	if (argc < 1)
		exit(EXIT_FAILURE);
	while (1)
	{
		ft_signals();
		view = readline("\e[1;32mminishell$ \e[0m");
		if (!view)
			break;
		view = ft_strtrim(view, " \n\t\r\v\f");
		check_quotes(view);
		gen.num_pipes = split_token(view, &gen.token);
		/* while (gen.token->next)
		{
			printf("token: %s\n", gen.token->str[0]);
			gen.token = gen.token->next;
		} */
		if (ft_strlen(view) != 0)
		{
			gen.args = count_txt(gen.token->str);
			add_history(view);
			t_token *current = gen.token;
			while (current != NULL)
				current = current->next;
			exec(&gen);
			ft_exec_builtins(&gen);
			free_tokens(gen.token);
			gen.token = gen.token->next;
		}
		free(view);
		gen.token = NULL;
		//tcsetattr(0, 0, &inf.termios);
	}
	return (EXIT_SUCCESS);
}
