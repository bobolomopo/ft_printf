/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:29:49 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 17:51:23 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_allocate(t_flags *flags)
{
	char *result;

	if (flags->width > flags->precision)
	{
		if (!(result = ft_strnew(flags->width + 4)))
			return (NULL);
	}
	else
	{
		if (!(result = ft_strnew(flags->precision + 4)))
			return (NULL);
	}
	return (result);
}
