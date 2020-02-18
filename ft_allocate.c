/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:29:49 by jandre            #+#    #+#             */
/*   Updated: 2020/02/18 19:04:53 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_allocate(int len, t_flags *flags)
{
	char *result;

	if (flags->width > flags->precision)
	{
		if (!(result = ft_strnew(flags->width + 1)))
			return (NULL);
	}
	else
	{
		if (!(result = ft_strnew(flags->precision + 1)))
			return (NULL);
	}
	return (result);
}
