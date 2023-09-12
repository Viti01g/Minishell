/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulherrer <ulherrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:59:57 by uherrero          #+#    #+#             */
/*   Updated: 2022/03/08 14:35:19 by ulherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	register char	*str_aux;
	register char	chr;

	chr = (char)c;
	str_aux = (char *)s - TRUE;
	while ('\0' != *(++str_aux))
		if (*str_aux == chr)
			return (str_aux);
	if ('\0' != chr)
		str_aux = NULL;
	return (str_aux);
}
