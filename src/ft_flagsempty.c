/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsempty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:57:08 by jandre            #+#    #+#             */
/*   Updated: 2020/02/19 16:07:51 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_flagsempty(t_flags *flags)
{
	int		i;
	char	*result;

	i = 0;
	if (!(result = ft_allocate(flags)))
		return (NULL);
	while (i < flags->width)
		result[i++] = ' ';
	return (result);
}
