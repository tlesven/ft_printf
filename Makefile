# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 20:25:38 by tlesven           #+#    #+#              #
#    Updated: 2013/12/19 00:30:39 by tlesven          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
LDFLAGS = -L ~/libft -lft
AR = ar
RAN = ranlib
ARFLAGS = -rc
RM = rm -rf

NAME = libftprintf.a
SRC = ft_printf.c \
	  ft_putnbr.c \
	  ft_putchar.c \
	  ft_itoa.c \
	  ft_strlen.c \
	  ft_putstr.c \
	  ft_args.c \
	  ft_unsigned_itoa.c \
	  ft_octal_itoa.c \
	  ft_x_itoa.c \
	  ft_arg_empty.c

OBJ=$(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
	$(RAN) $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
