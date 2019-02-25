# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/16 18:15:45 by tlesven           #+#    #+#              #
#    Updated: 2019/02/25 17:49:43 by tlesven          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Werror -Wextra
RM = rm -rf

NAME = ft_printf

SRC = ft_printf.c\
	  parse.c\
	  format_list.c\
	  dispatcher.c\
	  c.c\
	  s.c\
	  p.c\
	  d.c\
	  i.c\
	  o.c\
	  u.c\
	  x.c\
	  maj_x.c\
	  f.c\
	  modulo.c\
	  d_convert.c\
	  o_convert.c\
	  u_convert.c\
	  x_convert.c\
	  f_convert.c\
	  precision.c\
	  options.c\
	  hash_options.c
PATH_SRC = src

INCLUDES = includes/ft_printf.h
INCFLAGS = -I includes/

OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))
PATH_OBJ = obj

LIBFFLAGS = -L ./libft -lft
LIBFIFLAGS = -I ./libft/includes
MLIB = make -C ./libft

all: $(NAME)

$(NAME): $(OBJ)
		$(MLIB)
		#@$(CC) -o $(NAME) $(OBJ) $(LIBFFLAGS)
		@cp libft/libft.a ./libftprintf.a
		@ar rc libftprintf.a $(OBJ)

$(PATH_OBJ)/%.o : $(addprefix $(PATH_SRC)/, %.c) $(INCLUDES)
		@mkdir -p $(PATH_OBJ)
		@$(CC) -o $@ -c $< $(INCFLAGS) $(LIBFIFLAGS)

clean:
		$(RM) $(OBJ)

fclean: clean
		make fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

norme:
	norminette $(SRC) ft_script.h
