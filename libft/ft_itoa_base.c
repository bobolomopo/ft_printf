/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:38:59 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 17:13:00 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base(long long nbr, char *base)
{
	char	*result;
	int		baselen;
	int		nbrlen;
	int		i;

	
	baselen = ft_strlen(base);
	nbrlen = ft_nbrlen_base(nbr, baselen);
	if (nbr == 0)
	{
		if (!(result = ft_strnew(1)))
			return (NULL);
		result[0] = base[0];
		return (result);
	}
	if (!(result = ft_strnew(nbrlen)))
		return (NULL);
	i = 1;
	while (nbr != 0)
	{
		result[nbrlen - i++] = base[nbr % baselen];
		nbr /= baselen;
	}
	return (result);
}