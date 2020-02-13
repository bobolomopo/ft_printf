/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:41:42 by jandre            #+#    #+#             */
/*   Updated: 2020/02/11 18:36:46 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_check(t_buf *buffer)
{
	char	*temp;

	if (!buffer->str)
	{
		if (!(buffer->str = ft_strnew(BUFFER_SIZE_PRINTF)))
			return (-1);
	}
	if (buffer->pos == buffer->size)
	{
		if (!(temp = ft_strnew(buffer->size)))
			return (-1);
		buffer->str -= buffer->pos;
		ft_memmove(temp, buffer->str, buffer->size);
		free(buffer->str);
		buffer->size += BUFFER_SIZE_PRINTF;
		if (!(buffer->str = ft_strnew(buffer->pos + BUFFER_SIZE_PRINTF)))
			return (-1);
		ft_memmove(buffer->str, temp, buffer->size - BUFFER_SIZE_PRINTF);
		buffer->str += buffer->pos;
		free(temp);
	}
	return (1);
}

int		ft_checkflags(const char **format, t_flags *flags, va_list arguments)
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

int		ft_width(const char **format, t_flags *flags, va_list arguments)
{
	if (**format == '*')
	{
		flags->width = va_arg(arguments, int);
		*format += 1;
		return (0);
	}
	flags->width = ft_atoi(*format);
	*format += ft_nbrlen(flags->width);
	return (0);
}

int		ft_precision(const char **format, t_flags *flags, va_list arguments)
{
	*format += 1;
	if (**format == '*')
	{
		flags->precision = va_arg(arguments, int);
		*format += 1;
		return (0);
	}
	flags->precision = ft_atoi(*format);
	*format += ft_nbrlen(flags->precision);
	return (0);
}
