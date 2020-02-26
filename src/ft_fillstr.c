/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:15:29 by jandre            #+#    #+#             */
/*   Updated: 2020/02/26 16:06:42 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_flagsstr(char *arg, t_flags *flags)
{
	if (*arg == '0' && flags->precision == 0 && flags->checkprecision)
		return (ft_flagsempty_str(flags));
	if (flags->minus)
		return (ft_flagsminus_str(arg, flags));
	else if (flags->zero)
		return (ft_flagszero_str(arg, flags));
	return (ft_flagselse_str(arg, flags));
}

static char	*ft_fillnull()
{
	char	*result;

	if (!(result = ft_strnew(7)))
		return (NULL);
	result = "(null)";
	return (result);
}

int			ft_fillstr(t_buf *buffer, const char **format, va_list arguments,
		t_flags *flags)
{
	char	*arg;
	char	*str;
	char	*str2;
	char	*temp;

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		if (!(str2 = ft_fillnull()))
			return (-1);
	}
	else
	{
		if (!(str2 = ft_strdup(str)))
			return (-1);
	}
	if (!(arg = (ft_flagsstr(str2, flags))))
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
	while (**format != 's' && **format != 'c')
		*format += 1;
	*format += 1;
	free(temp);
	return (1);
}
