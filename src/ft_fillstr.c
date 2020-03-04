/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:15:29 by jandre            #+#    #+#             */
/*   Updated: 2020/03/02 12:06:07 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_flagsstr(char *arg, t_flags *flags)
{
	if (flags->width == 0 && flags->checkprecision)
		return (ft_flagsprecision_str(arg, flags));
	if (flags->minus)
		return (ft_flagsminus_str(arg, flags));
	return (ft_flagselse_str(arg, flags));
}

int			ft_fillstr(t_buf *buffer, const char **format, va_list arguments,
		t_flags *flags)
{
	char	*arg;
	char	*str;
	char	*temp;

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		if (!(arg = (ft_flagsstr("(null)", flags))))
			return (-1);
	}
	else
	{
		if (!(arg = (ft_flagsstr(str, flags))))
			return (-1);
	}
	temp = arg;
	if (ft_fill(arg, buffer, format, 's') < 0)
		return (-1);
	free(temp);
	return (1);
}
