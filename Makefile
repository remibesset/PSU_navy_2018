##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## TasK02 day10
##

SRC = src/main.c \
	src/verif_malloc.c \
	src/utils.c \
	src/utils2.c \
	src/create_map.c \
	src/display_map.c \
	src/base_handling.c \
	src/CPool.c \
	src/info_handling.c \
	src/get_next_line.c \
	src/error.c \
	src/hit_function.c \

CFLAGS = -g -Iinclude

OBJ = $(SRC:.c=.o)

NAME = navy

GCCWAY = gcc -o

all: $(NAME)

$(NAME): $(OBJ)
	$(GCCWAY) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
