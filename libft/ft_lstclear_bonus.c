/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:28:35 by jandre            #+#    #+#             */
/*   Updated: 2019/11/05 14:46:10 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*stru;
	t_list	*temp;

	if (!lst || !del)
		return ;
	stru = lst->next;
	ft_lstdelone(*lst, del);
	while (stru)
	{
		temp = stru->next;
		ft_lstdelone(stru, del);
		stru = temp;
	}
	return ;
}
