/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:01:30 by jandre            #+#    #+#             */
/*   Updated: 2019/11/04 19:37:32 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_freelst(t_list *temp2, void (*del)(void *))
{
	t_list	*temp;

	while (temp2)
	{
		temp = temp2->next;
		ft_lstdelone(temp2, del);
		temp2 = temp;
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;
	t_list	*temp2;

	if (!lst || !f || !del)
		return (NULL);
	if (!(result = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	temp2 = result;
	while (lst)
	{
		temp = lst->next;
		if (!(result->next = ft_lstnew(f(lst->content))))
			return (ft_freelst(temp2, del));
		lst = temp;
		result = result->next;
	}
	return (result);
}
