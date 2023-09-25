/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:53:39 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 20:03:39 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cast_dst;
	unsigned char	*cast_src;
	size_t			i;

	cast_dst = (unsigned char *)s1;
	cast_src = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (cast_dst[i] != cast_src[i])
			return (cast_dst[i] - cast_src[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	char dst[100] = "hola que tal";
	char src[] = "que";
	size_t n = 2;
	printf("%d", memcmp(dst, src, n));
//	printf("%s", ft_memcpy(dst, src, n));
}
*/
