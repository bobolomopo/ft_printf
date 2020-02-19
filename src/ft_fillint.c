/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:15:29 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 16:10:59 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_flagsint(char *arg, t_flags *flags)
{
	if (*arg == '0' && flags->precision == 0 && flags->checkprecision)
	{
		free(arg);
		return (ft_flagsempty(flags));
	}
	if (flags->minus)
		return (ft_flagsminus(arg, flags));
	else if (flags->zero)
		return (ft_flagszero(arg, flags));
	return (ft_flagselse(arg, flags));
}

int			ft_fillint(t_buf *buffer, const char **format, va_list arguments,
		t_flags *flags)
{
	char	*arg;
	int		i;
	char	*temp;

	i = va_arg(arguments, int);
	if (!(arg = (ft_flagsint(ft_itoa(i), flags))))
		return (-1);
	temp = arg;
	while (*arg)
	{
		if (ft_check(buffer) < 0)
			return (-1);
		*buffer->str = *arg;
		buffer->pos++;
		buffer->str++;
		arg++;
	}
	while (**format != 'd' && **format != 'i')
		*format += 1;
	*format += 1;
	free(temp);
	return (i);
}
