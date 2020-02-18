/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:15:14 by jandre            #+#    #+#             */
/*   Updated: 2020/02/18 20:01:46 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_width(const char **format, t_flags *flags, va_list arguments)
{
	if (**format == '*')
	{
		flags->width = va_arg(arguments, int);
		*format += 1;
		return (0);
	}
	if (**format >= '0' && **format <= '9')
	{
		flags->width = ft_atoi(*format);
		*format += ft_nbrlen(flags->width);
	}
	return (0);
}

static int	ft_precision(const char **format, t_flags *flags, va_list arguments)
{
	*format += 1;
	if (**format == '*')
	{
		flags->precision = va_arg(arguments, int);
		*format += 1;
		return (0);
	}
	if (**format >= '0' && **format <= '9')
	{
		flags->precision = ft_atoi(*format);
		*format += ft_nbrlen(flags->precision);
	}
	return (0);
}

int			ft_checkflags(const char **format, t_flags *flags,
		va_list arguments)
{
	while (**format == '-')
	{
		flags->minus = 1;
		*format += 1;
	}
	while (**format == '0')
	{
		flags->zero = 1;
		*format += 1;
	}
	if (((**format >= '0' && **format <= '9') || **format == '*'))
		ft_width(format, flags, arguments);
	if ((**format == '.'))
		ft_precision(format, flags, arguments);
	return (0);
}
