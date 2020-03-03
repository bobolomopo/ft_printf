/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:15:29 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 17:26:05 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_flagsunsigned(char *arg, t_flags *flags)
{
	if (*arg == '0' && flags->precision == 0 && flags->checkprecision)
		return (ft_flagsempty(flags));
	if (flags->minus)
		return (ft_flagsminus(arg, flags));
	else if (flags->zero)
		return (ft_flagszero(arg, flags));
	return (ft_flagselse(arg, flags));
}

int			ft_fillunsigned(t_buf *buffer, const char **format, va_list arguments,
		t_flags *flags)
{
	char				*arg;
	unsigned int		i;
	char				*temp;

	i = va_arg(arguments, unsigned int);
	if ((!(temp = ft_itoa_base((long long)i, "0123456789"))) || (!(arg = (ft_flagsunsigned(temp, flags)))))
		return (-1);
	free(temp);
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
	while (**format != 'u')
		*format += 1;
	*format += 1;
	free(temp);
	return (1);
}
