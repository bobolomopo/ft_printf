/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:24:53 by jandre            #+#    #+#             */
/*   Updated: 2019/10/30 08:58:01 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = -1;
	while (++i < (int)n)
		if (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i])
			return ((int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
	return (0);
}
