/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_toggle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:50:29 by uliherre          #+#    #+#             */
/*   Updated: 2022/06/16 19:51:50 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	BIT_TOGGLE(x,b) invierte el valor del bit b de x a su complemento
*/
unsigned char	ft_bit_toggle(unsigned char var, unsigned char bit)
{
	return (var ^= ft_bit(bit));
}
