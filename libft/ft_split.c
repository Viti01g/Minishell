/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:15:49 by uherrero          #+#    #+#             */
/*   Updated: 2023/06/06 18:19:05 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_split(char **str, int i)
{
	while (i-- >= ZERO)
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}

static size_t	ft_count_word(char const *s, char c)
{
	register size_t	size;

	size = ZERO;
	while ('\0' != *s)
	{
		while (*s == c && '\0' != *s)
			s++;
		while (*s != c && '\0' != *s)
			s++;
		if (*(s - 1) != c)
			size++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	register char		**str;
	register char const	*start;
	register size_t		i;
	register size_t		size;

	if (NULL == s)
		return (NULL);
	size = ft_count_word(s, c);
	str = (char **) ft_calloc(1 + size, sizeof(char *));
	if (NULL == str)
		return (NULL);
	i = ZERO;
	while (ZERO != size--)
	{
		while (*s == c)
			s++;
		start = s;
		while ('\0' != *s && *s != c)
			s++;
		str[i++] = ft_substr(start, ZERO, s - start);
		if (NULL == str[i - 1])
			ft_free_split(str, i);
	}
	return (str);
}
