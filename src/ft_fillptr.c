/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:15:16 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 18:31:32 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_flagsptr(char *arg, t_flags *flags)
{
	if (*arg == '0' && flags->precision == 0 && flags->checkprecision)
		return (ft_flagsempty_ptr(flags));
	if (flags->minus)
		return (ft_flagsminus_ptr(arg, flags));
	else if (flags->zero)
		return (ft_flagszero_ptr(arg, flags));
	return (ft_flagselse_ptr(arg, flags));
}

static int		ft_fill(t_buf *buffer, char *arg, const char **format)
{
	while (*arg)
	{
		if (ft_check(buffer) < 0)
			return (-1);
		*buffer->str = *arg;
		buffer->pos++;
		buffer->str++;
		arg++;
	}
	while (**format != 'p')
		*format += 1;
	*format += 1;
	return (1);
}

int				ft_fillptr(t_buf *buffer, const char **format,
		va_list arguments, t_flags *flags)
{
	char					*arg;
	void					*ptr;
	char					*temp;

	ptr = va_arg(arguments, void *);
	if (ptr == NULL)
	{
		if (!(arg = ft_flagsptr("0", flags)))
			return (-1);
	}
	else 
	{
		if ((!(temp = ft_itoa_base((unsigned long long)ptr, "0123456789abcdef")))
			|| (!(arg = ft_flagsptr(temp, flags))))
			return (-1);
		free(temp);
	}
	temp = arg;
	if (ft_fill(buffer, arg, format) < 0)
		return (-1);
	free(temp);
	return (1);
}
