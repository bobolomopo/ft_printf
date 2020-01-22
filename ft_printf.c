/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:43:07 by jandre            #+#    #+#             */
/*   Updated: 2020/01/22 17:39:32 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	arguments;
	t_buf	buffer;
	int		ret;
	int		i;

	buffer.pos = 0;
	buffer.str = NULL;
	buffer.size = BUFFER_SIZE_PRINTF;
	va_start(arguments, format);
	while (*format != '\0')
	{
		if (ft_check(&buffer) < 0)
			return (-1);
		if (*format == '%')
		{
			if ((i = ft_fillarg(&buffer, format, arguments)) < 0)
				return (-1);
			format += i;
		}
		*buffer.str = *format;
		buffer.pos++;
		format++;
		buffer.str++;
	}
	buffer.str = buffer.str - buffer.pos;
	write(1, buffer.str, buffer.pos);
	free(buffer.str);
	ret = buffer.pos;
	va_end(arguments);
	return (ret);
}

int		main()
{
	int i = 2345;
	ft_printf("123   %d   456789   %s   123456789\n", i, "abcdefg");
	printf("123   %d   456789   %s   123456789\n", i, "abcdefg");
	//system("leaks a.out");
	//printf("123456789\n");
	return (0);
}
