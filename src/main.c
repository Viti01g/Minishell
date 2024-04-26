
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
    gen.infile = NULL;
    gen.delim = NULL;
//	atexit(ft_leaks);
    ft_disable_ctrl_c_printing_chars();
    view = "a";
    if (argc < 1)
        exit(EXIT_FAILURE);
    init_vars(&gen, env);
    while (1)
    {
        ft_signals();
        view = readline("\e[1;32mminishell$ \e[0m");
        if (!view)
            break;
        if (ft_strlen(view) != 0 && check_quotes(view) == 1)
        {
            view = expander(view);
            gen.num_pipes = split_token(view, &gen.token);
            remove_quotes_from_tokens(gen.token);
            if (categorize_arguments(gen.token)) {
                free_tokens(gen.token);
                gen.token = NULL;
                continue;
            }
            if (check_syntax(gen.token)) {
                free_tokens(gen.token);
                gen.token = NULL;
                continue;
            }
            gen.args = count_txt(gen.token->str);
            add_history(view);
            t_token *current = gen.token;
            while (current != NULL)
                current = current->next;
            exec(&gen);
            free_tokens(gen.token);
            gen.token = NULL;
        }
        free(view);
        gen.token = NULL;
       // system("leaks -q minishell");
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
