# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 10:12:21 by tlesven           #+#    #+#              #
#    Updated: 2019/01/16 19:10:38 by tlesven          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Wall -Werror -Wextra -c -I includes/
AR=ar
RAN=ranlib
ARFLAGS=-rc
RM=rm -rf

NAME=libft.a
SRC=ft_strcat.c \
	ft_strdup.c \
	ft_strndup.c \
	ft_strncat.c \
	ft_strcpy.c \
	ft_strlen.c \
	ft_strncpy.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlcat.c \
	ft_memmove.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_strsplit.c \
	ft_strdeltab.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c\
	ft_lstaddtoend.c\
	ft_lstiter.c\
	ft_lstmap.c
OBJ=$(subst .c,.o,$(SRC))
PATHSRC=src/
PATHOBJ=obj/
FILEOBJ=$(addprefix $(PATHOBJ), $(OBJ))
FILESRC=$(addprefix $(PATHSRC), $(SRC))

all: $(NAME)

$(NAME): $(FILEOBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(FILEOBJ)
	@$(RAN) $(NAME)
	@echo "$(NAME) done"
	

$(FILEOBJ): $(FILESRC)
	@$(CC) $(CFLAGS) $(FILESRC)
	@mkdir obj
	@mv $(OBJ) $(PATHOBJ)
	@echo "objects done"

clean:
	@$(RM) obj
	@echo "objects deleted"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: clean fclean re all
