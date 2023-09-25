/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:33:38 by drubio-m          #+#    #+#             */
/*   Updated: 2022/04/10 20:03:06 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ret;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		del((*lst)->content);
		ret = *lst;
		*lst = (*lst)->next;
		free(ret);
	}
	*lst = NULL;
}
