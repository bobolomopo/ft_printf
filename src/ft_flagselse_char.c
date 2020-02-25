/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagselse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:45:19 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 19:13:48 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_fillelse(char *arg, char *result, t_flags *flags, int len)
{
	int		i;
	int		j;

	i = 0;
	while (flags->width && i < flags->width - len)
		result[i++] = ' ';
	j = i;
	while (i - j < len)
		result[i++] = *arg++;
}

char			*ft_flagselse_char(char *arg, t_flags *flags)
{
	int		len;
	char	*result;

	len = ft_strlen(arg);
	if (len > flags->precision && flags->checkprecision)
		len = flags->precision;
	if (!(result = ft_strnew(flags->width + len)))
		return (NULL);
	ft_fillelse(arg, result, flags, len);
	return (result);
}
