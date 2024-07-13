NAME = so_long
CC = cc
CFLAGS = -c -Wall -Wextra -Werror
LFLAGS = -L./libft -lft
IFLAGS = -I./libft
FILES = parse.c\
		parse_way.c\
		parse_utils.c\
		main.c\
		hooks.c\
		map.c\
		bonus.c

ifeq ($(shell uname -s), Darwin)
	MINILIBX_PATH = minilibx-opengl
	MLX_HEADER = -I$(MINILIBX_PATH)
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
else
	MINILIBX_PATH = minilibx-linux
	MLX_HEADER = -I$(MINILIBX_PATH)
	MLX_FLAGS = -L./$(MINILIBX_PATH) -lmlx -lm -lXext -lX11
endif

OBJS = $(FILES:.c=.o)

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(IFLAGS) $< -o $@

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) $(MLX_FLAGS) $(MLX_HEADER) -o $(NAME)

lib:
	cd libft && make
	cd $(MINILIBX_PATH) && make

clean:
	rm -f ./*.o libft/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re lib
