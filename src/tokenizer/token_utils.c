#include "minishell.h"

void	print_tokens(t_token **tokens)
{
	t_token	*current_token;
//	char	**current_words;
//	int		token_index;
//	int		word_index;
//	int		i;

	current_token = *tokens;
//	token_index = 1;
	while (current_token != NULL)
	{
	//	printf("\nToken %d\n", token_index);
//		current_words = current_token->str;
	//	printf("Token Type: %d\n", current_token->type);
	//	printf("Num of words: %d\n", current_token->words);
//		word_index = 1;
//		i = -1;
		/* while (current_words[++i])
			printf("Word %d: %s\n", word_index++, current_words[i]); */
		current_token = current_token->next;
//		token_index++;
	}
}

int	count_words(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
