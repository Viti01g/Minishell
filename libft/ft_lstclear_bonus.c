/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:10:01 by uherrero          #+#    #+#             */
/*   Updated: 2022/06/16 19:55:33 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (NULL != lst && NULL != *lst)
	{
		if (NULL != (*lst)->next)
			ft_lstclear((&(*lst)->next), del);
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
