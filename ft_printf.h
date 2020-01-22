/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:46:41 by jandre            #+#    #+#             */
/*   Updated: 2020/01/22 18:17:24 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef BUFFER_SIZE_PRINTF
#  define BUFFER_SIZE_PRINTF 100
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include "libft.h"
# include <stdarg.h>

typedef struct	s_buf
{
	char	*str;
	int		pos;
	int		size;
}				t_buf;
int				ft_check(t_buf *buffer);
int				ft_fillarg(t_buf *buffer, const char *format,
		va_list arguments);
int				ft_fillchar(t_buf *buffer, const char *format,
		va_list arguments);
int				ft_fillint(t_buf *buffer, const char *format,
		va_list arguments);
int				digit_count_hexa(unsigned long long ptr);
char			*ft_itoa_hexa(unsigned long long ptr);

#endif
