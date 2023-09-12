/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:05:27 by uherrero          #+#    #+#             */
/*   Updated: 2022/07/16 16:08:01 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	register char	*new;
	register size_t	bytes;
	register size_t	x;

	bytes = count * size;
	new = (char *) malloc(bytes);
	if (NULL != new)
	{
		x = ZERO;
		while (x < bytes)
		{
			new[x] = '\0';
			x++;
		}
	}
	return ((void *) new);
}
