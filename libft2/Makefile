# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jandre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 15:45:53 by jandre            #+#    #+#              #
#    Updated: 2020/02/19 17:11:15 by jandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isprint.c \
	  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	  ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	  ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
	  ft_strtrim.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_strmapi.c ft_split.c ft_isdigit.c ft_substr.c \
	  ft_strjoin.c ft_calloc.c ft_strdup.c ft_nbrlen.c ft_strnew.c \
	  ft_nbrlen_base.c ft_itoa_base.c
OBJ = $(SRC:.c=.o)
BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
		ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c
BOBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o:%.c
	@gcc $(FLAG) $(OPTION) $< -o $@

bonus: $(BOBJ)
	@ar rc $(NAME) $(BOBJ)

clean:
	@/bin/rm -f $(OBJ) $(BOBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
