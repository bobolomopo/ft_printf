/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsminus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:20:47 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 17:54:40 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_fillminus(char *arg, char *result, t_flags *flags, int len)
{
	int		j;

	j = 0;
	if (*arg == '-')
	{
		result[j] = *arg++;
		j++;
		flags->precision += 2;
	}
	while (j < flags->precision - len)
		result[j++] = '0';
	result[j++] = '0';
	result[j++] = 'x';
	while (*arg)
		result[j++] = *arg++;
	while (j < flags->width)
		result[j++] = ' ';
}

char		*ft_flagsminus_ptr(char *arg, t_flags *flags)
{
	int		len;
	char	*result;

	len = ft_strlen(arg);
	if (len < flags->width || len < flags->precision)
	{
		if (!(result = ft_allocate(flags)))
			return (NULL);
	}
	else
		return (ft_strjoin("0x", arg));
	ft_fillminus(arg, result, flags, len);
	return (result);
}
