/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsminus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:20:47 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 19:12:55 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_fillminus(char *arg, char *result, t_flags *flags, int len)
{
	int		j;

	j = 0;
	while (j < len)
		result[j++] = *arg++;
	while (j < flags->width)
		result[j++] = ' ';
}

char		*ft_flagsminus_str(char *arg, t_flags *flags)
{
	int		len;
	char	*result;

	len = ft_strlen(arg);
	if (len > flags->precision && flags->checkprecision)
		len = flags->precision;
	if (!(result = ft_strnew(flags->width + len)))
		return (NULL);
	ft_fillminus(arg, result, flags, len);
	return (result);
}
