/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:46:15 by uherrero          #+#    #+#             */
/*   Updated: 2022/07/16 16:07:20 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (NULL != new && NULL != lst)
	{
		*lst = ft_lstlast(*lst);
		if (NULL == *lst)
			*lst = new;
		else
			(*lst)->next = new;
	}
}

void	ft_lstadd_back_d(t_list_d **lst, t_list_d **new)
{
	if (NULL != new && NULL != lst)
	{
		*lst = (t_list_d *) ft_lstlast((t_list *) *lst);
		if (NULL == *lst)
			*lst = *new;
		else
		{
			(*lst)->next = *new;
			(*new)->prev = *lst;
		}
	}
}
