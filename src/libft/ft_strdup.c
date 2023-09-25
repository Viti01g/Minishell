/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:18:12 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 20:04:47 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;
	char	*print_ptr;

	i = ft_strlen(s1) + 1;
	ptr = ft_calloc(i, 1);
	if (!ptr)
		return (0);
	print_ptr = ptr;
	while (*s1 != 0)
		*(ptr++) = *(s1++);
	return (print_ptr);
}
