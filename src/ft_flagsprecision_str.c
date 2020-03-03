/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsprecision_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:07:59 by jandre            #+#    #+#             */
/*   Updated: 2020/03/02 12:21:57 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_flagsprecision_str(char *arg, t_flags *flags)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	if ((int)ft_strlen(arg) > flags->precision)
		len = flags->precision;
	else
		len = ft_strlen(arg);
	if (!(result = ft_strnew(len)))
		return (NULL);
	while (*arg && i < len)
		result[i++] = *arg++;
	return (result);
}
