NAME = cube

SRCS = main.c \
		key.c \
		raycasting.c \
		
		

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