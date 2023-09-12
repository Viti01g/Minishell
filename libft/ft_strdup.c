/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulherrer <ulherrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:59:13 by uherrero          #+#    #+#             */
/*   Updated: 2022/04/09 19:28:47 by ulherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	register char	*new;
	register size_t	size;

	size = ft_strlen(s1) + TRUE;
	new = (char *)ft_calloc(size, sizeof(char));
	if (NULL != new)
		ft_strlcpy(new, s1, size);
	return (new);
}
