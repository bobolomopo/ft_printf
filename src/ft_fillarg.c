/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:17:00 by jandre            #+#    #+#             */
/*   Updated: 2020/03/04 15:17:02 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_zeroflags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->checkprecision = 0;
}

int			ft_fillarg(t_buf *buffer, const char **format, va_list arguments)
{
	t_flags	flags;

	ft_zeroflags(&flags);
	*format += 1;
	ft_checkflags(format, &flags, arguments);
	if (**format == '%')
		ft_fillpct(buffer, format, &flags);
	else if (**format == 'd' || **format == 'i')
		ft_fillint(buffer, format, arguments, &flags);
	else if (**format == 'p')
		ft_fillptr(buffer, format, arguments, &flags);
	else if (**format == 's')
		ft_fillstr(buffer, format, arguments, &flags);
	else if (**format == 'c')
		ft_fillchar(buffer, format, arguments, &flags);
	else if (**format == 'u')
		ft_fillunsigned(buffer, format, arguments, &flags);
	else if (**format == 'x')
		ft_fillhexamin(buffer, format, arguments, &flags);
	else if (**format == 'X')
		ft_fillhexamaj(buffer, format, arguments, &flags);
	return (0);
}
