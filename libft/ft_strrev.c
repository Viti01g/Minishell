/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:25:09 by uliherre          #+#    #+#             */
/*   Updated: 2022/08/15 12:26:04 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swapchar(char *c1, char *c2)
{
	register char	aux;

	aux = *c1;
	*c1 = *c2;
	*c2 = aux;
}

void	ft_strrev(char *str)
{
	register char	*end;

	end = str + ft_strlen(str) - 1;
	while (str < end)
		ft_swapchar(str++, end--);
}
