/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:04:18 by uherrero          #+#    #+#             */
/*   Updated: 2022/07/14 17:36:20 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	register char const	*start;
	register char const	*end;
	register char		*str_ret;

	if (!s1)
		return (NULL);
	start = s1;
	while ('\0' != *s1 && ft_strchr(set, *s1))
		start = ++s1;
	while ('\0' != *s1)
		s1++;
	end = --s1;
	while (ft_strchr(set, *s1) && end >= start)
		end = --s1;
	if (end - start >= 0)
	{
		str_ret = (char *)ft_calloc(2 + end - start, sizeof(char));
		if (NULL == str_ret)
			return (str_ret);
		ft_strlcpy(str_ret, start, 2 + end - start);
	}
	else
		str_ret = (char *)ft_calloc(1, sizeof(char));
	return (str_ret);
}
