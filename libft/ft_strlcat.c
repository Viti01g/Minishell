/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:18:22 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 20:05:09 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	z;

	i = ft_strlen(dst);
	n = ft_strlen(src);
	z = 0;
	if (dstsize == 0)
		return (n);
	if (i > dstsize)
		return (n + dstsize);
	else
	{
		while (src[z] && (i + z) < dstsize)
		{
			dst[i + z] = src[z];
			z++;
		}
		if ((i + z) == dstsize && i < dstsize)
			dst[(i + z) - 1] = '\0';
		else
			dst[i + z] = '\0';
		return (i + n);
	}
}
