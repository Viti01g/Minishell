/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:26:16 by uherrero          #+#    #+#             */
/*   Updated: 2022/06/16 20:21:05 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	register const unsigned char	*s1_aux;
	register const unsigned char	*s2_aux;

	if (ZERO == n)
		return (ZERO);
	s1_aux = (const unsigned char *)s1;
	s2_aux = (const unsigned char *)s2;
	while (*s1_aux == *s2_aux && *s1_aux && n-- > 1)
	{
		s1_aux++;
		s2_aux++;
	}
	return (*s1_aux - *s2_aux);
}
