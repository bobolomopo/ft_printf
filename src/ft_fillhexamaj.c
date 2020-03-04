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

static char		*ft_flagshexa(char *arg, t_flags *flags)
{
	if (*arg == '0' && flags->precision == 0 && flags->checkprecision)
		return (ft_flagsempty(flags));
	if (flags->minus)
		return (ft_flagsminus(arg, flags));
	else if (flags->zero)
		return (ft_flagszero(arg, flags));
	return (ft_flagselse(arg, flags));
}

int				ft_fillhexamaj(t_buf *buffer, const char **format,
		va_list arguments, t_flags *flags)
{
	char					*arg;
	unsigned int			nbr;
	char					*temp;

	nbr = va_arg(arguments, unsigned int);
	if ((!(temp = ft_itoa_base((long long)nbr, "0123456789ABCDEF")))
		|| (!(arg = ft_flagshexa(temp, flags))))
		return (-1);
	free(temp);
	temp = arg;
	if (ft_fill(arg, buffer, format, 'X') < 0)
		return (-1);
	free(temp);
	return (1);
}
