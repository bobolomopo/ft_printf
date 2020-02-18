/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:46:41 by jandre            #+#    #+#             */
/*   Updated: 2020/02/18 19:48:55 by jandre           ###   ########.fr       */
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
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_buf
{
	char	*str;
	int		pos;
	int		size;
}				t_buf;
typedef struct	s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
}				t_flags;
int				ft_printf(const char *format, ...);
char			*ft_allocate(int len, t_flags *flags);
int				ft_nbrlen_un(unsigned int n);
char			*ft_itoa_un(unsigned int n);
int				ft_check(t_buf *buffer);
int				ft_checkflags(const char **format, t_flags *flags,
		va_list arguments);
int				ft_fillarg(t_buf *buffer, const char **format,
		va_list arguments);
int				ft_fillchar(t_buf *buffer, const char **format,
		va_list arguments);
int				ft_fillint(t_buf *buffer, const char **format,
		va_list arguments, t_flags *flags);
int				ft_fillptr(t_buf *buffer, const char **format,
		va_list arguments);
int				ft_filloctal(t_buf *buffer, const char **format,
		va_list arguments);
int				ft_fillhexa(t_buf *buffer, const char **format,
		va_list arguments);
int				ft_fillhexamaj(t_buf *buffer, const char **format,
		va_list arguments);
int				ft_fillunsigned(t_buf *buffer, const char **format,
		va_list arguments);
int				digit_count(unsigned long long ptr, int size);
char			*ft_itoa_base(long long nbr, char *base);
char			*ft_flagsminus(char *arg, t_flags *flags);
char			*ft_flagszero(char *arg, t_flags *flags);
char			*ft_flagselse(char *arg, t_flags *flags);

#endif
