/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:17:36 by jandre            #+#    #+#             */
/*   Updated: 2020/01/22 11:44:40 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(unsigned int size)
{
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(result, (size + 1));
	return (result);
}
