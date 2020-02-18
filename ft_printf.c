/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:43:07 by jandre            #+#    #+#             */
/*   Updated: 2020/02/17 18:15:07 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		arguments;
	t_buf		buffer;
	int			ret;
	int			i;

	buffer.pos = 0;
	buffer.str = NULL;
	buffer.size = BUFFER_SIZE_PRINTF;
	va_start(arguments, format);
	while (*format != '\0')
	{
		if (ft_check(&buffer) < 0)
			return (-1);
		if (*format == '%')
		{
			if ((ft_fillarg(&buffer, &format, arguments)) < 0)
				return (-1);
		}
		*buffer.str = *format;
		buffer.pos++;
		format++;
		buffer.str++;
	}
	buffer.str = buffer.str - buffer.pos;
	write(1, buffer.str, buffer.pos);
	free(buffer.str);
	ret = buffer.pos;
	va_end(arguments);
	return (ret);
}

int		ft_fillarg(t_buf *buffer, const char **format, va_list arguments)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.precision = 0;
	*format += 1;
	ft_checkflags(format, &flags, arguments);
	if (**format == 'd' || **format == 'i')
		ft_fillint(buffer, format, arguments, &flags);
	return (0);
}
