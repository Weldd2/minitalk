NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
CDEBUGFLAGS = -g

SRC = ft_handle.c ft_printf.c ft_utils.c ft_utils2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

debug: fclean $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.debug.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $(CDEBUGFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEBUG_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
