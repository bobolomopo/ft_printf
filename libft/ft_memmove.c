/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:28:07 by jandre            #+#    #+#             */
/*   Updated: 2019/10/30 08:58:26 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if ((!dst && !src) || src == dst)
		return (dst);
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (ptr2 < ptr1)
	{
		i++;
		while (i <= len)
		{
			ptr1[len - i] = ptr2[len - i];
			i++;
		}
	}
	else
		while (i < len)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	return (dst);
}
