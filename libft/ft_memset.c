/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:21:47 by uherrero          #+#    #+#             */
/*   Updated: 2022/06/16 19:20:11 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memset(void *dst, int c, size_t len)
{
	register size_t			size;
	register unsigned char	c_aux;
	register unsigned char	*dest;

	size = len;
	c_aux = (unsigned char)c;
	dest = dst;
	while (ZERO != size--)
		dest[size] = c_aux;
	return (dst);
}
