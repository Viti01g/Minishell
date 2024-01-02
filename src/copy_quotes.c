#include "minishell.h"

int	main(void)
{
	char	*input;
	char	*si;

	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		printf("%p\n", input);
		if (!input || !ft_strcmp(input, "exit"))
			break ;
//		check_quotes(input);
		si = retrieve_double_quote(input);
		free(si);
		free(input);
	}
	//system("leaks -q minishell");
	atexit(ft_leaks);
	return (0);
}