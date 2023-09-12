/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulherrer <ulherrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:49:39 by uherrero          #+#    #+#             */
/*   Updated: 2022/04/04 15:48:29 by ulherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	register const unsigned char	*source;
	register unsigned char			*destiny;
	register size_t					x;

	source = src;
	destiny = dst;
	x = -1;
	if (NULL != dst || NULL != src)
		while (++x < n)
			destiny[x] = source[x];
	return (dst);
}

void	*ft_memcpy_r(void *dst, const void *src, size_t n)
{
	register const unsigned char	*source;
	register unsigned char			*destiny;

	source = src;
	destiny = dst;
	if (NULL != dst || NULL != src)
		while (ZERO < n--)
			destiny[n] = source[n];
	return (dst);
}
