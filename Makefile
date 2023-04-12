NAME = so_long
CC = cc
CFLAGS = -c -Wall -Wextra -Werror
MLX = -lmlx -L /usr/local/include -framework AppKit -framework OpenGL
LFLAGS = -L./libft -lft
IFLAGS = -I./libft
FILES = parse.c\
		parse_way.c\
		parse_utils.c\
		main.c\
		hooks.c\
		map.c\

OBJS = $(FILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) $< -o $@

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) $(MLX) -o $(NAME)

lib:
	cd libft && make

clean:
	rm -f ./*.o libft/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re lib