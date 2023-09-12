/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulherrer <ulherrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:36:04 by uherrero          #+#    #+#             */
/*   Updated: 2022/03/08 14:34:35 by ulherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*str_aux;
	register unsigned char	c_aux;

	c_aux = (unsigned char)c;
	str_aux = (const unsigned char *)s;
	while (n--)
	{
		if (c_aux == *str_aux)
			return ((void *)str_aux);
		str_aux++;
	}
	return (NULL);
}
