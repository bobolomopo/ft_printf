/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:21:07 by jandre            #+#    #+#             */
/*   Updated: 2019/10/30 09:00:14 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = (char *)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (result);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i + j] == needle[j])
		{
			j++;
			while (haystack[i + j] == needle[j] && (i + j) < len && needle[j]
					&& haystack[i + j])
				j++;
			if (needle[j] == '\0')
				return (result + i);
		}
		i++;
	}
	return (NULL);
}
