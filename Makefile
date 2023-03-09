NAME = so_long
CC = cc
CFLAGS = -c -Wall -Wextra -Werror
MLX = -lmlx -L /usr/local/include -framework AppKit -framework OpenGL
LFLAGS = -L./ft_printf -lftprintf -L./libft -lft
IFLAGS = -I./libft -I./ft_printf
FILES = parse.c\
		parse_way.c\
		parse_utils.c\
		main.c\
		hooks.c\
		map.c\

OBJS = $(FILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) $< -o $@

all: lib ftprintf $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) $(MLX) -o $(NAME)

ftprintf:
	cd ft_printf && make

lib:
	cd libft && make

clean:
	rm -f ./*.o libft/*.o ft_printf/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re lib ftprintf