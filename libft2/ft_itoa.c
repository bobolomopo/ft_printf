/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:05:33 by jandre            #+#    #+#             */
/*   Updated: 2019/11/04 18:11:35 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	size_t			i;
	unsigned int	nbr;
	char			*result;

	i = ft_nbrlen(n);
	nbr = (unsigned int)n;
	if (!(result = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		result[i] = '0' + (nbr % 10);
		nbr = nbr / 10;
		i--;
	}
	return (result);
}
