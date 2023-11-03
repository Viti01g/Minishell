#include "../headers/minishell.h"

/* int	main(int argc, char **argv, char **env)
{
	char		*view;
	t_general	gen;
	char		**manolo;
	int			i;

	manolo = argv;
	manolo = env;


	view = "a";
	if (argc != 1)
		exit(EXIT_FAILURE);
	while (1)
	{
		view = readline("\e[1;32mminishell$ \e[0m");

		if (ft_strlen(view) > 0)
		{

			i = -1;
			add_history(view);
			gen.linea_entera = ft_split(view, ' ');
			while (gen.linea_entera[i++])
				printf("Token: %s  tipo: %d\n", gen.linea_entera[i], -7);
			free(view);
		}
	}
	return (EXIT_SUCCESS);
} */

int	main(void) {
    char *input;
    char *fragment;
    int i;
    int j;

    while (1) {
        input = readline("\e[1;32mminishell$ \e[0m");
        if (!input) 
            break;
        i = 0;
        j = 0;
        while (input[i]) 

		{
            if (input[i] == '|' || input[i] == '<' || input[i] == '>') 
			{
				fragment = ft_substr(input, j, i - j);
                printf("Token: %s\n", fragment);
				if ((input[i] == '>' || input[i] == '<') && input[i] == input[i + 1])
				{
					fragment = ft_substr(input, i, 2);
					printf("Token: %s\n", fragment);
					i++;
				}
				else
				{
                	fragment = ft_substr(input, i, 1);
                	printf("Token: %s\n", fragment);
				}
                j = i + 1;
            }
            i++;
        }
        // *Imprimimos el último token después del bucle
        fragment = ft_substr(input, j, i - j);
        printf("Token: %s\n", fragment);
        free(input);
    }
    return 0;
}

/* 
	TODO: Partir función del main
	TODO: guardar en una lista enlazada
 
 */