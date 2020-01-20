# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbelov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 18:46:10 by kbelov            #+#    #+#              #
#    Updated: 2019/12/17 18:48:44 by kbelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAG = -Wall -Wextra -Werror

SRC = main.c input.c output.c get_next_line.c

OBJ = *.o

LIBFT = ./libft/*.c

HEADER = fdf.h

FRAMEWORKS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): lib
	gcc $(FLAG) $(SRC) libft/libft.a minilibx_macos/libmlx.a $(FRAMEWORKS) -o $(NAME)

lib:
	@make -C libft

libmlx:
	@make -C minilibx_macos

clean:
	@/bin/rm -rf $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

lldb: lib
	gcc -g $(FLAG) $(SRC) $(LIBFT) minilibx_macos/libmlx.a $(FRAMEWORKS) -o fdf_lldb 

norme:
	norminette main.c input.c output.c get_next_line.c /libft/* fdf.h get_next_line.h

cleanrepo:
	@/bin/rm -rf fdf_lldb fdf_lldb.dSYM 
