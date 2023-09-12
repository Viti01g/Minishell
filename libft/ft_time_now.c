/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_now.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:52:14 by uliherre          #+#    #+#             */
/*   Updated: 2023/06/06 18:19:26 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_time_now(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		ft_puterror("gettimeofday() ft_time_now()");
	return ((time.tv_sec * _1K) + (time.tv_usec / _1K));
}
