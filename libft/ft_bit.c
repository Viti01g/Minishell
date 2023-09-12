/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:50:32 by uliherre          #+#    #+#             */
/*   Updated: 2022/06/16 19:50:52 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	regresa el bit x puesto a uno y los demas bits en cero
*	ej. BIT(3) regresa 00001000 && BIT(0) regresa 00000001
*/
unsigned char	ft_bit(unsigned char x)
{
	return (1 << x);
}
