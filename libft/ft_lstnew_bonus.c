/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:27:29 by uherrero          #+#    #+#             */
/*   Updated: 2022/07/02 14:29:16 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) ft_calloc(TRUE, sizeof(t_list));
	if (NULL != new)
	{
		new->next = NULL;
		new->content = content;
	}
	return (new);
}

t_list_d	*ft_lstnew_d(void *content)
{
	t_list_d	*new;

	new = (t_list_d *) ft_calloc(TRUE, sizeof(t_list_d));
	if (NULL != new)
	{
		new->next = NULL;
		new->prev = NULL;
		new->content = content;
	}
	return (new);
}
