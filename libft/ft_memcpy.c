/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:54:26 by jandre            #+#    #+#             */
/*   Updated: 2019/10/30 08:58:14 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	if ((src == NULL && dst == NULL) || dst == src)
		return (dst);
	i = -1;
	while (++i < (int)n)
		((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}
