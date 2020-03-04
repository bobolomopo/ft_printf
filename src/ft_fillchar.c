/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:15:29 by jandre            #+#    #+#             */
/*   Updated: 2020/03/02 12:06:07 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_flagschar(char *arg, t_flags *flags)
{
	if (flags->width == 0 && flags->checkprecision)
		return (ft_flagsprecision_str(arg, flags));
	if (flags->minus)
		return (ft_flagsminus_str(arg, flags));
	return (ft_flagselse_str(arg, flags));
}

static int	ft_fillminus(t_buf *buffer, t_flags *flags, int c)
{
	int		i;

	i = -1;
	if (ft_check(buffer) < 0)
		return (-1);
	*buffer->str = (char)c;
	buffer->pos++;
	buffer->str++;
	while (++i < flags->width - 1)
	{
		if (ft_check(buffer) < 0)
			return (-1);
		*buffer->str = ' ';
		buffer->pos++;
		buffer->str++;
	}
	return (1);
}

static int	ft_fillelse(t_buf *buffer, t_flags *flags, int c)
{
	int i;

	i = -1;
	while (++i < flags->width - 1)
	{
		if (ft_check(buffer) < 0)
			return (-1);
		*buffer->str = ' ';
		buffer->pos++;
		buffer->str++;
	}
	if (ft_check(buffer) < 0)
		return (-1);
	*buffer->str = (char)c;
	buffer->pos++;
	buffer->str++;
	return (1);
}

static int	ft_fillnonprint(t_buf *buffer, t_flags *flags,
	const char **format, int c)
{
	if (flags->minus == 1)
	{
		if (ft_fillminus(buffer, flags, c) < 0)
			return (-1);
	}
	else
	{
		if (ft_fillelse(buffer, flags, c) < 0)
			return (-1);
	}
	while (**format != 'c')
		*format += 1;
	*format += 1;
	return (1);
}

int			ft_fillchar(t_buf *buffer, const char **format, va_list arguments,
		t_flags *flags)
{
	char	*arg;
	int		c;
	char	*temp;

	c = va_arg(arguments, int);
	if (c < 32 || c > 127)
	{
		if (ft_fillnonprint(buffer, flags, format, c) < 0)
			return (-1);
	}
	else
	{
		if (!(temp = ft_strnew(1)))
			return (-1);
		temp[0] = (char)c;
		if (!(arg = (ft_flagschar(temp, flags))))
			return (-1);
		free(temp);
		temp = arg;
		if (ft_fill(arg, buffer, format, 'c') < 0)
			return (-1);
		free(temp);
	}
	return (1);
}
