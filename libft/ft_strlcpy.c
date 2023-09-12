/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:55:29 by uherrero          #+#    #+#             */
/*   Updated: 2022/07/16 16:10:25 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	register const char	*str;
	register size_t		x;

	x = dstsize;
	str = src;
	if (ZERO != dstsize)
	{
		while (ZERO != --dstsize)
		{
			*(dst++) = *(src++);
			if ('\0' == *(dst - 1))
				break ;
		}
	}
	if (ZERO == dstsize)
	{
		if (ZERO != x)
			*dst = '\0';
		while ('\0' != *(src++))
			;
	}
	return (src - str - 1);
}
