/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:11:09 by drubio-m          #+#    #+#             */
/*   Updated: 2024/01/08 16:41:50 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

static int	skip_spaces(char *str)
{
	int	j;

	j = 0;
	while (is_whitespace(str[j]))
		j++;
	return (j);
}

void	p_quotes_cmd(char *s, size_t *i, int *in_quotes, char *current_quote)
{
    if (*in_quotes && *current_quote == s[*i]) 
        *in_quotes = 0;
    else if (!*in_quotes)
	{
        *in_quotes = 1;
        *current_quote = s[*i];
    }
    (*i)++;
}

void	process_delimiter(char *s, size_t *i, size_t *word_count, char c, int in_quotes)
{
    if (!in_quotes && s[*i] == c) 
    {
        (*word_count)++;
        while (s[*i] && s[*i] == c)
            (*i)++;
    } 
    else 
        (*i)++;
}

static size_t	ft_count_words(char *s, char c)
{
    size_t	word_count;
    size_t	i;
    int		in_quotes;
    char	current_quote;

    word_count = 0;
    i = 0;
    in_quotes = 0;
    current_quote = '\0';
    i += skip_spaces(s);
    while (s[i])
    {
        if (s[i] == '\'' || s[i] == '\"') 
        {
            p_quotes_cmd(s, &i, &in_quotes, &current_quote);
            continue ;
        }
        process_delimiter(s, &i, &word_count, c, in_quotes);
    }
    if (s[i - 1] != c && !in_quotes)
        word_count++;
	printf("Esta es la cuenta: %zu\n", word_count);
    return (word_count);
}

/* static void	ft_free_split(char **str, size_t words)
{
	while (words > 0)
	{
		free(str[words]);
		words--;	
	}
	free(str);
} */

void	process_delimiter_split(char *s, size_t *i, char c, int in_quotes)
{
    if (!in_quotes && s[*i] == c) 
    {
        while (s[*i] && s[*i] == c)
            (*i)++;
    } 
    else 
        (*i)++;
}

void	process_word(char *s, size_t *i, int *in_quotes, char *current_quote)
{
    if (s[*i] == '\'' || s[*i] == '\"') 
        p_quotes_cmd(s, i, in_quotes, current_quote);
    else 
        (*i)++;
}

void skip_delimiters(char *s, size_t *start, char c, int in_quotes)
{
    if (s[*start] != '\0') // Check if not at the end of the string
    {
        while (s[*start] == c && !in_quotes) // Skip delimiters after a word only if not in quotes
            (*start)++;
    }
}

char	*get_next_word(char *s, size_t *start, char c)
{
    size_t	i;
    int		in_quotes;
    char	current_quote;
    char    *word;

    i = *start;
    in_quotes = 0;
    current_quote = '\0';
    while (s[i] && (s[i] != c || in_quotes))
    {
        if (s[i] == '\'' || s[i] == '\"') 
        {
            p_quotes_cmd(s, &i, &in_quotes, &current_quote);
            continue ;
        }
       else 
           i++;
    }
    word = ft_substr(s, *start, (i - *start));
    *start = i;
	skip_delimiters(s, start, c, in_quotes);
    return word;
}

char	**ft_split_cmd(char *s, char c)
{
    char	**words;
    size_t	i;
    size_t	start;
    size_t	word_count;

    if (!s)
        return (NULL);
    word_count = ft_count_words(s, c);
    words = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!words)
        return (NULL);
    i = 0;
    start = 0;
    while (s[start] == c && s[start] != '\0')
        start++;
    while (i < word_count)
    {
        words[i] = get_next_word(s, &start, c);
        if (words[i] == NULL)
            break ;
        i++;
    }
    words[i] = NULL;
    return (words);
}

//*****************************************************************************
// INPUT
// #1. La string a separar.
// #2. El caracter delimitador.
//*****************************************************************************
// OUTPUT
// El array de strings resultante. NULL si la reserva falla.
//*****************************************************************************
// DESCRIPTION
// Reserva con malloc(3) y devuelve un array de strings obtenido al separar 
// ’s’ con el caracter ’c’ como delimitador. El array debe terminar en NULL.
//*****************************************************************************


/* int main(void)
{
char s[] = " pedro' h o\"la'a\"pito\"     c' pedro' n ";
//char s[] = "'hola' 'mundo'";
//char s[] = "\"hola\" \"mundo\"";
char c = ' ';
char **res;
int i = 0;
res = ft_split_cmd(s, ' ');
while (res[i])
{
	printf("%s\n", res[i]);
	i++;
}
printf("%s\n", res[i]);
//system("leaks a.out");
return (0);
} */
