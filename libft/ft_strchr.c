/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:02:23 by jandre            #+#    #+#             */
/*   Updated: 2019/10/30 08:58:57 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*result;
	char	test;

	i = 0;
	test = (char)c;
	result = (char *)s;
	while (s[i])
	{
		if (s[i] == test)
			return (result + i);
		i++;
	}
	if (s[i] == c)
		return (result + i);
	return (NULL);
}
