/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:15:29 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 18:36:23 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_flagspct(char *arg, t_flags *flags)
{
	flags->precision = 0;
	flags->checkprecision = 0;
	if (flags->minus)
		return (ft_flagsminus(arg, flags));
	else if (flags->zero)
		return (ft_flagszero(arg, flags));
	return (ft_flagselse(arg, flags));
}

int			ft_fillpct(t_buf *buffer, const char **format, t_flags *flags)
{
	char	*arg;
	char	*temp;
	char	*pct;

	if (!(pct = ft_strnew(1)))
		return (-1);
	pct[0] = '%';
	if (!(arg = (ft_flagspct(pct, flags))))
		return (-1);
	free(pct);
	temp = arg;
	if (ft_fill(arg, buffer, format, '%') < 0)
		return (-1);
	free(temp);
	return (1);
}
