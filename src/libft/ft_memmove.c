/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:10:08 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 20:03:59 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cast_dst;
	char	*cast_src;
	size_t	i;

	cast_dst = (char *) dst;
	cast_src = (char *) src;
	i = 0;
	if (cast_dst == 0 && cast_src == 0)
		return (0);
	if (cast_dst > cast_src)
		while (len--)
			cast_dst[len] = cast_src[len];
	else
	{
		while (i < len)
		{
			cast_dst[i] = cast_src[i];
			i++;
		}
	}
	return (cast_dst);
}
