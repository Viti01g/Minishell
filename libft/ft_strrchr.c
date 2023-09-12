/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulherrer <ulherrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:14:27 by uherrero          #+#    #+#             */
/*   Updated: 2022/03/08 14:35:46 by ulherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	register char	*str_aux;
	register char	c_aux;

	c_aux = (char)c;
	str_aux = NULL;
	while ('\0' != *s)
	{
		if (*s == c_aux)
			str_aux = (char *)s;
		s++;
	}
	if (NULL == str_aux)
		if (ZERO == c_aux)
			str_aux = (char *)s;
	return (str_aux);
}
