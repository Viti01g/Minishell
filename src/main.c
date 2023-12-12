
#include "../headers/minishell.h"

void	view_prompt(void)
{
	write(1, GREEN, ft_strlen(GREEN));
	write(1, "minishell$ ", strlen("minishell$ "));
	write(1, RESET, ft_strlen(RESET));
}
int	main(int argc, char **argv, char **env)
{
	char		*view;
	t_general	gen;
	char		**manolo;
	int  o;

	o = 0;
	manolo = argv;
	manolo = env;

	ft_disable_ctrl_c_printing_chars();
	view = "a";
	if (argc != 1)
		exit(EXIT_FAILURE);
	
	while (1)
	{
		ft_signals();
		view = readline("\e[1;32mminishell$ \e[0m");
		if (!view)
			break;

		if (ft_strlen(view) != 0)
		{
			add_history(view);
			gen.linea_entera = ft_split(view, ' ');
			while (*gen.linea_entera != NULL) {
				printf("Token: %s\n", *gen.linea_entera);
				gen.linea_entera++;
			}
			//prueba
			free(view);
		}
		tcsetattr(0, 0, &g_info.termios);
	}
	return (EXIT_SUCCESS);
}
