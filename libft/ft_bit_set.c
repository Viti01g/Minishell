/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:50:26 by uliherre          #+#    #+#             */
/*   Updated: 2022/06/16 19:51:45 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	BIT_SET(x,b) establece en '1' el bit BIT de VAR
*	ej. BIT_SET(VAR, 4)
*/
unsigned char	ft_bit_set(unsigned char var, unsigned char bit)
{
	return (var |= ft_bit(bit));
}
/*	11110111 OR 00001000 == 11111111
*/
