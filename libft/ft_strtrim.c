/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:58:40 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 20:06:24 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_valid_set(char c, char const *set)
{
	unsigned long	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}	
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned long	i;
	unsigned long	start;
	unsigned long	end;

	start = 0;
	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1);
	while (s1[start] && ft_valid_set(s1[start], set))
		start++;
	while (end > start && ft_valid_set(s1[end - 1], set))
		end --;
	str = ft_calloc(sizeof (char), (end - start) + 1);
	if (!str)
		return (0);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	return (str);
}
//****************************************************************************
// INPUT
//#1. La string a recortar.
//#2. El conjunto de caracteres utilizado como referencia para el recorte.
//****************************************************************************
// OUTPUT
//La string recortada. NULL si falla la reserva. 
//****************************************************************************
// DESCRIPTION
// Reserva con malloc(3) y devuelve una copia de ’s1’ con los caracteres 
// dados en ’set’ eliminados tanto del principio como del final.
//****************************************************************************
/*
int	main(void)
{
	char s1[] = "hola que \t tal te encuentras hola";
	char set[]	= "hola";
	printf("%s", ft_strtrim(s1, set));
}
*/
