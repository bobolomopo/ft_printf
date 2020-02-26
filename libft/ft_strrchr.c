/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:14:56 by jandre            #+#    #+#             */
/*   Updated: 2019/10/30 09:00:20 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = ft_strlen(s);
	result = (char *)s;
	while (i >= 0)
	{
		if (result[i] == (char)c)
			return (result + i);
		i--;
	}
	return (NULL);
}
