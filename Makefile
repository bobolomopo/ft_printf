# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jandre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 13:41:52 by jandre            #+#    #+#              #
#    Updated: 2020/03/02 11:29:48 by jandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRC := ft_allocate.c ft_check.c ft_checkflags.c ft_fillint.c ft_flagselse.c \
	ft_flagsminus.c ft_flagszero.c ft_printf.c ft_flagsempty.c ft_fillptr.c \
	ft_flagsempty_ptr.c ft_flagszero_ptr.c ft_flagsminus_ptr.c \
	ft_flagselse_ptr.c ft_fillpct.c ft_fillstr.c ft_flagsempty_str.c \
	ft_flagselse_str.c ft_flagsminus_str.c ft_flagsprecision_str.c \
	ft_fillhexamin.c ft_fillhexamaj.c ft_fillunsigned.c ft_fillchar.c \
	ft_fill.c ft_fillarg.c
SRC_DIR = ./src
OBJECTS := $(SRC:.c=.o)
LIBRARIES = libftprintf.a ./libft/libft.a
SRC := $(addprefix $(SRC_DIR)/, $(SRC))
INC_DIR = ./includes/
LIB_DIR = ./libft/

(NAME):
	@echo "\033[1mcreating libft.a and copying...\033[1m"
	@echo "\033[32m\033[1m\033mdone!\033[0m"
	@make -C ./libft --no-print-directory
	@cp ./libft/libft.a $(NAME)
	@echo "\033[1mcleaning libft directory...\033[0m"
	@make clean -C ./libft --no-print-directory
	@echo "\033[32m\033[1m\033mdone!\033[0m"
	@echo "\033[1mcreating ft_printf objects...\033[0m"
	@gcc $(FLAGS) -c $(SRC) -I$(INC_DIR) -I$(LIB_DIR)
	@echo "\033[32m\033[1m\033mdone!\033[0m"
	@echo "\033[1mcreating libftprintf.a library...\033[0m"
	@ar -rc $(NAME) $(OBJECTS)
	@echo "\033[32m\033[1m\033mdone!\033[0m"

all: $(NAME)

test:
	@gcc $(FLAGS) $(SRC) test.c libft/libft.a includes/ft_printf.h && ./a.out

clean:
	@echo "\033[31m\033[1mcleaning...\033[0m"
	@rm -f $(OBJECTS)
	@echo "ft_printf objects removed!"

fclean: clean
	@make fclean -C ./libft --no-print-directory
	@rm -f $(NAME)
	@echo "libftprintf.a removed!"

re: fclean
	@make

.PHONY: clean fclean re
