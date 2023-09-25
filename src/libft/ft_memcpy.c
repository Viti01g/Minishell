/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:37:22 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 20:03:56 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cast_dst;
	char	*cast_src;
	size_t	i;

	cast_dst = (char *) dst;
	cast_src = (char *) src;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		cast_dst[i] = cast_src[i];
		i++;
	}
	return (cast_dst);
}
