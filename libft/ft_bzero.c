/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:39:49 by uherrero          #+#    #+#             */
/*   Updated: 2022/07/04 15:43:43 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	register char	*dst;
	register size_t	x;

	dst = (char *)s;
	x = ZERO;
	while (x != n)
	{
		dst[x] = '\0';
		x++;
	}
}
