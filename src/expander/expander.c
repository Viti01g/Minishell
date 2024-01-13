#include "minishell.h"

int	main(void)
{
	char	*input;
	t_token	*tokens;

	//atexit(ft_leaks);
	tokens = NULL;
//	printf("%p\n", input);
//	printf("%s\n", input);
	while (1)
	{
		input = readline("\e[1;32mminishell$ \e[0m");
		if (!input || !ft_strcmp(input, "exit"))
			break ;
		check_quotes(input);
		split_token(input, &tokens);
		free(input);
		free_tokens(tokens);
		tokens = NULL;
	}
	return (0);
}
