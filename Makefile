# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 15:57:46 by nyaacc            #+#    #+#              #
#    Updated: 2020/02/22 17:46:29 by gnelson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
NAME = fillit
LIB_NAME = libft.a
CS =	main.c \
		read_file.c \
		tetrimino.c \
		points.c \
		place_tetrimino.c \
		square.c \
		solve.c \
		lst_utilites.c \
		tetri_utilites.c
CFLAGS = -Wall -Wextra -Werror
LIB_OPT = -L./includes/libft/ -lft
OBJS = $(patsubst %.c, %.o, $(CS))
OPTION1 = -I./includes -I./includes/libft/includes
VPATH = includes

all: $(NAME)

$(NAME):
	@make -C includes/libft re
	@$(CC) $(CFLAGS) $(OPTION1) -c $(CS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_OPT) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C includes/libft clean

fclean: clean
	@rm -f .$(LIB_NAME) $(NAME)
	@make -C includes/libft fclean

re: fclean all


.PHONY: all clean fclean re