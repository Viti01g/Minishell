/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulherrer <ulherrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:16:50 by uherrero          #+#    #+#             */
/*   Updated: 2022/03/08 14:35:43 by ulherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	register unsigned int	flag;
	size_t					len_aux;
	register const char		*needle_aux;
	register const char		*hayst_aux;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && len--)
	{
		needle_aux = (const char *)needle;
		hayst_aux = (const char *)haystack;
		if (*needle_aux == *hayst_aux)
		{
			len_aux = len + 1;
			flag = 1;
			while (*needle_aux && flag)
				if (*(needle_aux++) != *(hayst_aux++) || !len_aux--)
					flag = ZERO;
			if (flag)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
