/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:43:07 by jandre            #+#    #+#             */
/*   Updated: 2020/03/02 13:54:20 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_fillprintf(t_buf *buffer, const char **format, va_list arguments)
{
	while (**format != '\0')
	{
		if (ft_check(buffer) < 0)
			return (-1);
		if (**format == '%')
		{
			if (ft_fillarg(buffer, format, arguments) < 0)
				return (-1);
		}
		else
		{
			*buffer->str = **format;
			buffer->pos++;
			*format += 1;
			buffer->str++;
		}
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list		arguments;
	t_buf		buffer;
	int			ret;

	buffer.pos = 0;
	buffer.str = NULL;
	buffer.size = BUFFER_SIZE_PRINTF;
	va_start(arguments, format);
	ft_fillprintf(&buffer, &format, arguments);
	buffer.str = buffer.str - buffer.pos;
	write(1, buffer.str, buffer.pos);
	free(buffer.str);
	ret = buffer.pos;
	va_end(arguments);
	return (ret);
}
