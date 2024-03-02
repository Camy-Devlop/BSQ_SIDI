CC=cc
CFLAGS=-Wall -Wextra -Werror

INCLUDES_DIR=includes

SRC=src/main.c src/ft_atoi.c src/ft_check_file.c src/ft_error.c src/ft_file.c src/ft_putstr.c src/ft_read_and_solve.c src/ft_solve.c src/ft_split.c src/ft_strlen.c src/ft_utils.c
OBJ=$(SRC:.c=.o)

NAME=bsq

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $^ -o $@

$(NAME): $(OBJ)
	$(CC) -g $(OBJ) -o $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all $(NAME) re clean fclean
