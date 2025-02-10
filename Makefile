CC = cc
FT_PRINTF = ./FT_PRINTF/libftprintf.a
SRC = check_map.c main.c moves.c rendering.c free.c prints.c ft_strdup.c check_valid_path.c
GNLSRC = ./GET_NEXT_LINE/get_next_line.c ./GET_NEXT_LINE/get_next_line_utils.c
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
OBG = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBG)
	@cd FT_PRINTF && make
	$(CC) $(CFLAGS) $(OBG) $(GNLSRC) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)

%.o:%.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@cd ./FT_PRINTF && make clean
	@rm -f $(OBG)

fclean: clean
	@rm -f $(FT_PRINTF)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re