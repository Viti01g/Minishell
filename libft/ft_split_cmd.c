/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:11:09 by drubio-m          #+#    #+#             */
/*   Updated: 2024/01/07 20:21:02 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

int	skip_spaces(char *str)
{
	int	j;

	j = 0;
	while (is_whitespace(str[j]))
		j++;
	return (j);
}

/* static size_t	process_quotes(char *str, size_t i, char del)
{
    size_t	j;

    j = i;
    i++;
    while (str[i] != del && str[i])
        i++;
    if (str[i] == del)
        i++;
    return (i - j);
}

static size_t	ft_count_words(char const *s, char c)
{
    size_t	word_count;
    size_t	i;
    int		in_quotes;
    char	current_quote;

    word_count = 0;
    i = 0;
    in_quotes = 0;
    current_quote = '\0';
	i += skip_spaces((char *)s);
    while (s[i])
    {
        if (s[i] == '\'' || s[i] == '\"') 
		{
            if (in_quotes && current_quote == s[i])
                in_quotes = 0;
			else if (!in_quotes) 
			{
                in_quotes = 1;
                current_quote = s[i];
            }
        }
        if (!in_quotes && s[i] == c) 
		{
            word_count++;
            while (s[i] && s[i] == c)
                i++;
        } 
		else 
            i++;
    }
    if (s[i - 1] != c)
        word_count++;
    printf("Esta es la cuenta: %zu\n", word_count);
    return (word_count);
} */

















static void	process_quotes(char const *s, size_t *i, int *in_quotes, char *current_quote)
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

static void	process_delimiter(char const *s, size_t *i, size_t *word_count, char c, int in_quotes)
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

static size_t	ft_count_words(char const *s, char c)
{
    size_t	word_count;
    size_t	i;
    int		in_quotes;
    char	current_quote;

    word_count = 0;
    i = 0;
    in_quotes = 0;
    current_quote = '\0';
    i += skip_spaces((char *)s);
    while (s[i])
    {
        if (s[i] == '\'' || s[i] == '\"') 
        {
            process_quotes(s, &i, &in_quotes, &current_quote);
            continue;
        }
        process_delimiter(s, &i, &word_count, c, in_quotes);
    }
    if (s[i - 1] != c && !in_quotes)
        word_count++;
	printf("Esta es la cuenta: %zu\n", word_count);
    return (word_count);
}


/* static size_t	ft_count_words(char const *s, char c)
{
    size_t	word_count;
    size_t	i;
    int		in_quotes;
    char	current_quote;

    word_count = 0;
    i = 0;
    in_quotes = 0;
    current_quote = '\0';
    i += skip_spaces((char *)s);
    while (s[i])
    {
        if (s[i] == '\'' || s[i] == '\"') 
		{
            process_quotes(s, &i, &in_quotes, &current_quote);
            continue ;
        }
        if (!in_quotes && s[i] == c) 
		{
            word_count++;
            while (s[i] && s[i] == c)
                i++;
        } 
		else 
            i++;
    }
    if (s[i - 1] != c)
        word_count++;
    printf("Esta es la cuenta: %zu\n", word_count);
    return (word_count);
} */

static void	ft_free_split(char **str, size_t words)
{
	while (words > 0)
	{
		free(str[words]);
		words--;	
	}
	free(str);
}

char	**ft_split_cmd(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;
	size_t	index;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = ft_calloc(sizeof (char *), (ft_count_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i] && (index < ft_count_words(s, c)))
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		str[index++] = ft_substr(s, j, (i - j));
	}
	if (!str)
		ft_free_split(str, ft_count_words(s, c));
	return (str);
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


int main(void)
{
//char s[] = " pedro' h o\"la'a     c' pedro' n";
char s[] = "'hola' 'mundo'";
char c = ' ';
char **res;
res = ft_split_cmd(s, ' ');
while (*res)
{
	printf("%s\n", *res++);
}
//system("leaks a.out");
return (0);
}

