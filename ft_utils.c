/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:57:00 by jandre            #+#    #+#             */
/*   Updated: 2020/01/22 18:17:34 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		digit_count_hexa(unsigned long long ptr)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}


char	*ft_itoa_hexa(unsigned long long ptr)
{
	char	*base;
	char	*result;
	int		nbrlen;
	int		i;

	if (!(result = ft_strnew(digit_count_hexa(ptr))) || !(base =
			   ft_strnew(16)))
		return (NULL);
	base = "0123456789ABCDEF";
	i = 1;
	nbrlen = digit_count_hexa(ptr);
	while (value != 0)
	{
		ret[nbrlen - i++] = tab_base[value % base];
		value /= 16;
	}
	free(tab_base);
	return (result);
}
