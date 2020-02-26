/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:40:08 by jandre            #+#    #+#             */
/*   Updated: 2019/11/04 12:31:04 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*stru;

	if (!(stru = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	stru->content = content;
	stru->next = NULL;
	return (stru);
}
