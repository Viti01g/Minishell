/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:12:19 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 20:03:32 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*cast_s;

	i = 0;
	cast_s = (char *) s;
	while (i < n)
	{
		if (cast_s[i] == (char)c)
			return (cast_s + i);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	char s[] = {0, 1, 2, 3, 4, 5};
	int c  = 2 + 256;
	size_t n = 3;
	printf("%s", ft_memchr(s, c, n));
//	puts(s);
}
*/
