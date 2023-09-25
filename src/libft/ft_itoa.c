/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:32:40 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 20:02:58 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_turn_to_positive(int n)
{	
	if (n < 0)
		n = -n;
	return (n);
}

char	*ft_itoa(int n)
{
	char		*ret;
	long int	def_num;
	int			intlen;

	intlen = ft_intlen(n);
	ret = ft_calloc(sizeof (char), (ft_intlen(n) + 1));
	def_num = ft_turn_to_positive(n);
	if (!ret)
		return (0);
	if (n == 0)
		ret[0] = '0';
	if (n == (-2147483647 -1))
		def_num = 2147483648;
	while (intlen-- > 0)
	{
		ret[intlen] = ((def_num % 10) + '0');
		def_num = def_num / 10;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
/*
int	main(void)
{
	int n = (-2147483647 -1);
	printf("%s\n", ft_itoa(n));
	printf("%d", ft_intlen(-2147483647));
}
*/
