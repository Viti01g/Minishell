/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:06:34 by uherrero          #+#    #+#             */
/*   Updated: 2022/06/16 20:43:14 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	register const unsigned char	*source;
	register unsigned char			*destiny;
	register size_t					loop;
	register unsigned char			c_aux;

	if (ZERO != n)
	{
		source = (unsigned char *) src;
		destiny = (unsigned char *) dst;
		loop = n;
		c_aux = c;
		while (ZERO < loop--)
		{
			*(destiny) = *(source);
			if (*destiny == c_aux)
				return (++destiny);
			destiny++;
			source++;
		}
	}
	return (NULL);
}
