NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

FILES = $(wildcard *.c)

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@rm -f *.o

fclean: clean
	@rm -f libftprintf.a

re: fclean all

.PHONE: all clean fclean re