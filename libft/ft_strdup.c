/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:18:12 by drubio-m          #+#    #+#             */
/*   Updated: 2023/10/31 13:02:05 by drubio-m         ###   ########.fr       */
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

/*************************************
se utiliza para duplicar una cadena de caracteres. 
Recibe una cadena como entrada y crea una nueva copia 
idéntica de la cadena original en una ubicación de memoria distinta. 
Esto es útil para preservar la cadena original mientras se trabaja con una copia
de ella, evitando así modificar la cadena original accidentalmente o 
garantizando que la memoria se libere adecuadamente cuando ya no sea necesaria.
**************************************/