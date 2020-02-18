/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:41:42 by jandre            #+#    #+#             */
/*   Updated: 2020/02/18 19:02:57 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_check(t_buf *buffer)
{
	char	*temp;

	if (!buffer->str)
	{
		if (!(buffer->str = ft_strnew(BUFFER_SIZE_PRINTF)))
			return (-1);
	}
	if (buffer->pos == buffer->size)
	{
		if (!(temp = ft_strnew(buffer->size)))
			return (-1);
		buffer->str -= buffer->pos;
		ft_memmove(temp, buffer->str, buffer->size);
		free(buffer->str);
		buffer->size += BUFFER_SIZE_PRINTF;
		if (!(buffer->str = ft_strnew(buffer->pos + BUFFER_SIZE_PRINTF)))
			return (-1);
		ft_memmove(buffer->str, temp, buffer->size - BUFFER_SIZE_PRINTF);
		buffer->str += buffer->pos;
		free(temp);
	}
	return (1);
}
