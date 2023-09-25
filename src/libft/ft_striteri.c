/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:53:07 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 20:04:50 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

//*****************************************************************************
// INPUT
// s: La string que iterar.
// f: La función a aplicar sobre cada carácter
//*****************************************************************************
// OUTPUT
// Nada
//*****************************************************************************
// DESCRIPTION
// A cada carácter de la string ’s’, aplica la función ’f’ 
// dando como parámetros el índice de cadacarácter dentro de ’s’ 
// y la dirección del propio carácter, que podrá modificarse si es necesario.
//*****************************************************************************

/*
int main(void)
{

}
*/
