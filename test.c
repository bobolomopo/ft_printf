/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:58:07 by jandre            #+#    #+#             */
/*   Updated: 2020/02/18 21:53:35 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int	main()
{
	int d = -42128;
	printf("%0.*d et %0.*i\n", 15, d, 15, d);
	ft_printf("%0.*d et %0.*i\n", 15, d, 15, d);
	printf("%0*d\n", 15, d);
	ft_printf("%0*d\n", 15, d);
	printf("%0*.12d\n", 15, d);
	ft_printf("%0*.12d\n", 15, d);
	printf("%*.17d\n", 15, d);
	ft_printf("%*.17d\n", 15, d);
	printf("%-*.12d\n", 15, d);
	ft_printf("%-*.12d\n", 15, d);
	printf("%45.10d\n", d);
	ft_printf("%45.10d\n", d);
	printf("%*.60d\n", 15, d);
	ft_printf("%*.60d\n", 15, d);
	printf("%*.8d\n", 60, d);
	ft_printf("%*.8d\n", 60, d);
	printf("%0*.2d\n", 15, d);
	ft_printf("%0*.2d\n", 15, d);
	printf("%0*.12d\n", 15, d);
	ft_printf("%0*d\n", 15, d);
	printf("%0*.12d\n", 15, d);
	ft_printf("%0*d\n", 15, d);
	printf("%0*.12d\n", 15, d);
	ft_printf("%0*d\n", 15, d);
	printf("%0*.12d\n", 15, d);
	ft_printf("%0*d\n", 15, d);
	printf("%0*.12d\n", 15, d);
	return (0);
}
