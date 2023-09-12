/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:03:01 by uherrero          #+#    #+#             */
/*   Updated: 2022/07/17 21:54:22 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	register char	*nw_str;
	register char	*start;

	if (NULL == s1 || NULL == s2)
		return (NULL);
	nw_str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	start = nw_str;
	if (NULL != nw_str)
	{
		while ('\0' != *s1)
			*(nw_str++) = *(s1++);
		while ('\0' != *s2)
			*(nw_str++) = *(s2++);
	}
	return (start);
}
