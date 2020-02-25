/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagszero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:57:19 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 18:42:45 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_flagszero_char(char *arg, t_flags *flags)
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
	return (ft_flagselse_char(arg, flags));
}
