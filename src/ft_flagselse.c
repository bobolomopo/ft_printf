/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagselse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:45:19 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 16:01:41 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_fillelse(char *arg, char *result, t_flags *flags, int len)
{
	int		i;
	int		j;

	i = 0;
	while (flags->width && i < flags->width - flags->precision)
		result[i++] = ' ';
	if (*arg == '-')
	{
		result[i++] = '-';
		arg++;
	}
	j = i;
	while (i - j < flags->precision - len)
		result[i++] = '0';
	while (*arg)
		result[i++] = *arg++;
}

char			*ft_flagselse(char *arg, t_flags *flags)
{
	char	*temp;
	int		len;
	char	*result;

	temp = arg;
	len = ft_strlen(arg);
	if (len < flags->width || len < flags->precision)
	{
		if (!(result = ft_allocate(flags)))
			return (NULL);
	}
	else
		return (arg);
	if (*arg == '-' && flags->precision)
		flags->precision++;
	if (flags->precision == 0 || flags->precision < len)
		flags->precision = len;
	ft_fillelse(arg, result, flags, len);
	free(temp);
	return (result);
}
