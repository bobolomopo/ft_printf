/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagszero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:57:19 by jandre            #+#    #+#             */
/*   Updated: 2020/02/18 20:02:33 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flagszero(char *arg, t_flags *flags)
{
	if (flags->precision == 0)
	{
		if (*arg == '-')
		{
			flags->precision = flags->width - 1;
			flags->width = 0;
		}
		else
		{
			flags->precision = flags->width;
			flags->width = 0;
		}
	}
	return (ft_flagselse(arg, flags));
}
