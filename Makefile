# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 20:36:05 by mbarylak          #+#    #+#              #
#    Updated: 2023/05/17 20:37:46 by mbarylak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube

SRCS = main.c \
		error_msg.c get_map_info.c ./gnl/get_next_line.c\
		key.c raycasting.c \
		

OBJS = $(SRCS:.c=.o)

FLAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Werror -Wextra 

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS)  $(OBJS) -o $(NAME)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
		./cube

.PHONY: all, clean, fclean, re