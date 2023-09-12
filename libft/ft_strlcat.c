/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:05:35 by uherrero          #+#    #+#             */
/*   Updated: 2022/06/16 21:10:03 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	register size_t	n;
	register size_t	len_src;
	register size_t	len_dst;

	n = ZERO;
	len_src = ft_strlen(src);
	len_dst = ZERO;
	if (ZERO != dstsize)
		len_dst = ft_strlen(dst);
	while (*dst && dstsize > 1)
	{
		dst++;
		dstsize--;
		n++;
	}
	while (*src && dstsize-- > 1)
	{
		*(dst++) = *(src++);
		n++;
	}
	if (n > len_dst)
		*dst = ZERO;
	if (len_dst > ++n)
		len_dst = n;
	return (len_src + len_dst);
}
