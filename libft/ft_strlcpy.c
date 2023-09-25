/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:56:37 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 20:05:29 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (dstsize < 1)
		return (i);
	while (src[j] && j < dstsize - 1)
	{
		dst[j] = src[j];
		j++;
	}
		dst[j] = '\0';
	return (i);
}
/*
int main(void)
{
	char dst[100] = "hola que tal";
	char *src = "adios";
	size_t n = 2;
	//printf("%lu\n", ft_strlcpy(dst, src, n));
	//printf("%lu\n", strlcpy(dst, src, n));
//	printf("%lu\n", strlcpy(((void *)0), ((void *)0), 10));
	printf("%lu\n", ft_strlcpy(((void *)0), ((void *)0), 10));
}
*/
