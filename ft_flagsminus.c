/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsminus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:20:47 by jandre            #+#    #+#             */
/*   Updated: 2020/02/18 20:01:56 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	while (*arg)
		result[j++] = *arg++;
	while (j < flags->width)
		result[j++] = ' ';
}

char		*ft_flagsminus(char *arg, t_flags *flags)
{
	char	*temp;
	int		len;
	char	*result;

	temp = arg;
	len = ft_strlen(arg);
	if (len < flags->width || len < flags->precision)
	{
		if (!(result = ft_allocate(len, flags)))
			return (NULL);
	}
	else
		return (arg);
	ft_fillminus(arg, result, flags, len);
	free(temp);
	return (result);
}
