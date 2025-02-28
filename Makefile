CC = cc
SRC =	check_map.c check_valid_path.c free.c ft_hexhelper.c ft_printf.c ft_putchar.c ft_puthex.c \
		ft_putnbr.c  ft_putstr.c  ft_putunbr.c  ft_strdup.c  get_next_line.c get_next_line_utils.c \
		main.c	moves.c	prints.c	rendering.c

CFLAGS = -Wall -Wextra -Werror
NAME = so_long
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
OBG = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $(OBG) $(MLX_FLAGS) -o $(NAME)

%.o: %.c ft_printf.h get_next_line.h so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBG)

fclean: clean
	@rm -f $(NAME)

re: fclean all

mk: all clean

.PHONY: clean