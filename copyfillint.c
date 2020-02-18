/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:15:29 by jandre            #+#    #+#             */
/*   Updated: 2020/02/18 17:53:30 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	*format += ft_nbrlen(i);
	free(temp);
	return (i);
}

char		*ft_allocate(char *arg, t_flags *flags)
{
	int		i;
	char	*result;

	i = ft_strlen(arg);
	if (i < flags->width || i < flags->precision)
	{
		if (flags->width > flags->precision)
		{
			if (!(result = ft_strnew(flags->width + 1)))
				return (NULL);
		}
		else
		{
			if (!(result = ft_strnew(flags->precision + 1)))
				return (NULL);
		}
	}
	else
		return (arg);
}

char		*ft_flagsint(char *arg, t_flags *flags)
{
	char	*result;

	if (flags->minus)
		return (ft_flagsminus(arg, flags));
	else if (flags->zero)
		return (ft_flagszero(arg, flags));
	return (ft_flagselse(arg, flags));
}

char		*ft_flagsminus(char *arg, t_flags *flags)
{
	char	*temp;
	int		i;
	int		j;
	char	*result;

	temp = arg;
	i = ft_strlen(arg);
	j = 0;
	if (i < flags->width || i < flags->precision)
	{
		if (flags->width > flags->precision)
		{
			if (!(result = ft_strnew(flags->width + 1)))
				return (NULL);
		}
		else
		{
			if (!(result = ft_strnew(flags->precision + 1)))
				return (NULL);
		}
	}
	else
		return (arg);
	if (*arg == '-')
	{
		result[j] = *arg++;
		j++;
		flags->precision += 2;
	}
	while (j < flags->precision - i)
	{
		result[j] = '0';
		j++;
	}
	while (*arg)
	{
		result[j] = *arg++;
		j++;
	}
	while (j < flags->width)
	{
		result[j] = ' ';
		j++;
	}
	free(temp);
	return (result);
}

char		*ft_flagszero(char *arg, t_flags *flags)
{
	if (flags->width > flags->precision)
	{
		if (*arg == '-')
		{
			flags->precision = flags->width - 1;
			flags->width = 0;
		}
		else
		{
			flags->precision = flags->width;
			flags->width = 0;
		}
	}
	return (ft_flagselse(arg, flags));
}

char		*ft_flagselse(char *arg, t_flags *flags)
{
	char    *temp;
	int     i;
	int     j;
	int		k;
	char    *result;

	temp = arg;
	i = ft_strlen(arg);
	j = 0;
	if (i < flags->width && flags->width > flags->precision)
	{
		if (!(result = ft_strnew(flags->width + 1)))
			return (NULL);
	}
	else if (i < flags->precision && flags->precision >= flags->width)
	{
		if (!(result = ft_strnew(flags->precision + 1)))
			return (NULL);
	}
	else
		return (arg);
	if (*arg == '-' && flags->precision)
		flags->precision++;
	if (flags->precision == 0 || flags->precision < i)
		flags->precision = i;
	while (flags->width && j < flags->width - flags->precision)
	{
		result[j] = ' ';
		j++;
	}
	if (*arg == '-')
	{
		result[j] = '-';
		j++;
		arg++;
		k = j;
	}
	while (j - k < flags->precision - i)
	{
		result[j] = '0';
		j++;
	}
	while (*arg)
		result[j++] = *arg++;
	free(temp);
	return (result);
}
