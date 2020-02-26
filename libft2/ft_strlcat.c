/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:48:09 by jandre            #+#    #+#             */
/*   Updated: 2019/10/30 08:59:34 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	retour;

	i = 0;
	retour = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	retour += i;
	j = 0;
	if (i >= size)
		return (retour);
	while (i + j < size - 1 && src[j])
	{
		dst[j + i] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (retour);
}
