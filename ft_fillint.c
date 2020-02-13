/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:15:29 by jandre            #+#    #+#             */
/*   Updated: 2020/02/13 11:44:13 by jandre           ###   ########.fr       */
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

char		*ft_flagsint(char *arg, t_flags *flags)
{
	char	*result;

	if (flags->minus)
		return (ft_flagsminus(arg, flags));
	else if (flags->zero && (flags->precision > flags->width))
		return (ft_flagszero(arg, flags));
	else
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
			if (!(result = ft_strnew(flags->width)))
				return (NULL);
		}
		else
		{
			if (!(result = ft_strnew(flags->precision)))
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
			if (!(result = ft_strnew(flags->width)))
				return (NULL);
		}
		else
		{
			if (!(result = ft_strnew(flags->precision)))
				return (NULL);
		}
	}
	else
		return (arg);
	if (*arg == '-')
	{
		result[j] = *arg++;
		j++;
		flags->width += 1;
	}
	while (j < flags->width - i)
	{
		result[j] = '0';
		j++;
	}
	while (*arg)
	{
		result[j] = *arg++;
		j++;
	}
	return (result);

}
char		*ft_flagselse(char *arg, t_flags *flags)
{
	char    *temp;
	int     i;
	int     j;
	char    *result;

	temp = arg;
	i = ft_strlen(arg);
	j = 0;
	if (i < flags->width && flags->width > flags->precision)
	{
		if (!(result = ft_strnew(flags->width)))
			return (NULL);
	}
	else if (i < flags->precision && flags->precision >= flags->width)
	{
		if (*arg == '-')
		{
			if (!(result = ft_strnew(flags->precision + 1)))
				return (NULL);
		}
		else
		{
			if (!(result = ft_strnew(flags->precision)))
				return (NULL);
		}
	}
	else
		return (arg);
	while (flags->width - i && flags->width > flags->precision)
	{
		result[j] = ' ';
		flags->width--;
		j++;
	}
	if (*arg == '-')
	{
		result[j] = '-';
		flags->precision += 2;
		j++;
		arg++;
	}
	while (j < flags->precision - i)
	{
		result[j] = '0';
		j++;
	}
	while (*arg)
		result[j++] = *arg++;
	free(temp);
	return (result);
}
