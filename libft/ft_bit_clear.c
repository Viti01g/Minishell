/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:50:20 by uliherre          #+#    #+#             */
/*   Updated: 2023/06/06 18:21:58 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	BIT_CLEAR(x,b) establece en '0' el bit BIT de VAR
*	ej. BIT_CLEAR(VAR, 4)
*/
unsigned char	ft_bit_clear(unsigned char var, unsigned int bit)
{
	return (var &= ~ft_bit(bit));
}
/*	ej. 11111111 AND 11110111 == 11110111
*/
