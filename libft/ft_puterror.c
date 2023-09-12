/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:44 by uliherre          #+#    #+#             */
/*   Updated: 2023/06/06 18:18:45 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puterror(const char *error)
{
	if (NULL != error)
	{
		write(STDERR_FILENO, "Error: ", 7 * sizeof(char));
		write(STDERR_FILENO, error, ft_strlen(error) * sizeof(char));
		write(STDERR_FILENO, "\n", sizeof(char));
	}
	exit(-42);
}
