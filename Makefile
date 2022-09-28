.PHONY: all clean fclean re
NAME = fdf
CC = gcc
CFLAGS = -L.. -lmlx -L/usr/X11/include/../lib -lXext -lX11 -lm #-Wall -Wextra -Werror -g3 -fsanitize=address
SRC = tests.c extra.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)    

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all