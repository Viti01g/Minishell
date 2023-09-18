/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:40:49 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 23:21:17 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstret;
	t_list	*noderet;
	t_list	*contentret;

	if (!lst)
		return (NULL);
	lstret = NULL;
	while (lst)
	{
		contentret = (*f)(lst->content);
		noderet = ft_lstnew(contentret);
		if (!noderet)
		{
			ft_lstclear(&noderet, del);
			return (NULL);
		}
		ft_lstadd_back(&lstret, noderet);
		lst = lst->next;
	}
	return (lstret);
}
