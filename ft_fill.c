/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:35:42 by jandre            #+#    #+#             */
/*   Updated: 2020/01/22 18:20:16 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_fillarg(t_buf *buffer, const char *format, va_list arguments)
{
	format++;
	if (*format == 's' || *format == 'c')
		return (ft_fillchar(buffer, format, arguments));
	if (*format == 'd' || *format == 'i')
		return (ft_fillint(buffer, format, arguments));
	if (*format == 'p')
		return (ft_fillptr(buffer, format, arguments));
	return (0);
}

int			ft_fillchar(t_buf *buffer, const char *format, va_list arguments)
{
	char	*arg;
	int		i;
	char	c;

	c = *format;
	i = 1;
	i++;
	arg = va_arg(arguments, char *);
	while (*arg)
	{
		if (ft_check(buffer) < 0)
			return (-1);
		*buffer->str = *arg;
		buffer->pos++;
		buffer->str++;
		arg++;
	}
	return (i);
}

int			ft_fillint(t_buf *buffer, const char *format, va_list arguments)
{
	char	*arg;
	int		i;
	char	c;

	c = *format;
	i = va_arg(arguments, int);
	printf("%d\n", i);
	arg = ft_itoa(i);
	while (*arg)
	{
		if (ft_check(buffer) < 0)
			return (-1);
		*buffer->str = *arg;
		buffer->pos++;
		buffer->str++;
		arg++;
	}
	arg -= ft_nbrlen(i);
	free(arg);
	return (i);
}
