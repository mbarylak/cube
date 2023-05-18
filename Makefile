# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 20:36:05 by mbarylak          #+#    #+#              #
#    Updated: 2023/05/18 20:02:23 by mbarylak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube

PARSER = error_msg get_map_info parser
GNL = get_next_line

SRCS = $(addsuffix .c, $(addprefix parser/, $(PARSER))) \
		$(addsuffix .c, $(addprefix gnl/, $(GNL))) \
		key.c raycasting.c main.c \
		

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