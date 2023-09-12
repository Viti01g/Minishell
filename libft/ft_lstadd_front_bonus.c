/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:09:21 by uherrero          #+#    #+#             */
/*   Updated: 2022/07/16 16:07:09 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (NULL != new && NULL != *lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_front_d(t_list_d **lst, t_list_d **new)
{
	if (NULL != new && NULL != *lst)
	{
		(*lst)->prev = *new;
		(*new)->next = *lst;
		*lst = *new;
	}
}
