/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:41:47 by uliherre          #+#    #+#             */
/*   Updated: 2022/06/16 19:46:12 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define CAST (unsigned)

int	ft_isxdigit(int c)
{
	if (CAST c - '0' < 10 || CAST c - 'a' < 6 || CAST c - 'A' < 6)
		return (TRUE);
	return (FALSE);
}
