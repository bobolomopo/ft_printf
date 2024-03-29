/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:15:14 by jandre            #+#    #+#             */
/*   Updated: 2020/03/02 12:05:24 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_width(const char **format, t_flags *flags, va_list arguments)
{
	if (**format == '*')
	{
		flags->width = va_arg(arguments, int);
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->minus = 1;
		}
		*format += 1;
		return (0);
	}
	if (**format >= '0' && **format <= '9')
	{
		flags->width = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			*format += 1;
	}
	return (0);
}

static int	ft_precision(const char **format, t_flags *flags, va_list arguments)
{
	flags->checkprecision = 1;
	*format += 1;
	if (**format == '*')
	{
		flags->precision = va_arg(arguments, int);
		*format += 1;
		if (flags->precision < 0)
			flags->checkprecision = 0;
		return (0);
	}
	if (**format >= '0' && **format <= '9')
	{
		flags->precision = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			*format += 1;
	}
	return (0);
}

int			ft_checkflags(const char **format, t_flags *flags,
		va_list arguments)
{
	while (**format == '0')
	{
		flags->zero = 1;
		*format += 1;
	}
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
	if (flags->minus || flags->checkprecision)
		flags->zero = 0;
	if (((**format >= '0' && **format <= '9') || **format == '*'))
		ft_width(format, flags, arguments);
	if ((**format == '.'))
		ft_precision(format, flags, arguments);
	return (0);
}
