/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2020/02/06 12:58:07 by jandre            #+#    #+#             */
/*   Updated: 2020/03/02 19:06:12 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int	main()
{
	char *str = "abc";
	printf("|%-*.*s|\n", 7, 3, "yolo");
	ft_printf("|%-*.*s|\n", 7, 3, "yolo");
	printf("|%*i && %p && %p|\n", -32, 100, str, str);
	printf("|%p && %2p && %2p && %-42p|\n", str, str, str, str);
	printf("|%23p && %23p|\n", str, str);
	ft_printf("|%*i && %p && %p|\n", -32, 100, str, str);
	ft_printf("|%p && %2p && %2p && %-42p|\n", str, str, str, str);
	ft_printf("|%23p && %23p|\n", str, str);
	return (0);
}
