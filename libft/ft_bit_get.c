/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:50:23 by uliherre          #+#    #+#             */
/*   Updated: 2022/06/16 19:51:14 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	regresa el bit BIT de VAR ej. BIT_GET(VAR, 3)
*/
unsigned char	ft_bit_get(unsigned char var, unsigned char bit)
{
	return (var & ft_bit(bit));
}
