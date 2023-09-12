/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulherrer <ulherrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:32:17 by uherrero          #+#    #+#             */
/*   Updated: 2022/04/09 19:25:25 by ulherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	register char	*new;
	register size_t	tam;

	if (NULL == s)
		return (NULL);
	tam = ft_strlen(s);
	new = (char *)ft_calloc(tam + 1, sizeof(char));
	if (NULL != new)
		while (ZERO != tam--)
			new[tam] = f(tam, s[tam]);
	return (new);
}
