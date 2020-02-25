/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsempty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:57:08 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 18:07:05 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_flagsempty_ptr(t_flags *flags)
{
	int		i;
	char	*result;

	i = 0;
	if (!(result = ft_allocate(flags)))
		return (NULL);
	while (i + 2 < flags->width)
		result[i++] = ' ';
	result[i++] = '0';
	result[i++] = 'x';
	return (result);
}
