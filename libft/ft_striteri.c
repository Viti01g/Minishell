/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:57:40 by uliherre          #+#    #+#             */
/*   Updated: 2022/06/16 20:57:41 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	register char	*str;
	register size_t	tam;

	str = s;
	if (NULL != str)
	{
		tam = ft_strlen(str);
		while (ZERO != tam--)
			f(tam, &str[tam]);
	}
}
