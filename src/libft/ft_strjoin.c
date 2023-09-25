/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:08:10 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 20:05:03 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (str == (0))
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	return (str);
}
// ***************************************************************************
// INPUT
// #1. La string prefijo.
// #2. La string sufijo.
// ***************************************************************************
// OUTPUT
// La nueva string. NULL si la reserva falla.
// ***************************************************************************
// DESCRIPTION
// Reserva con malloc(3) una nueva string, basada en
// la unión de las dos strings dadas como parámetros.
// ***************************************************************************
/*
int main(void)
{
	char	s1[]= "hola";
	char	s2[]= "que tal";
	printf("%s\n", ft_strjoin(s1, s2));
}
*/
