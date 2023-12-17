NAME_CLIENT = client
NAME_SERVER = server
LIBFTPRINTF = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
SRC_SERVER = server.c

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):
	$(CC) $(CFLAGS) $(SRC_CLIENT) -L. -lftprintf -o $(NAME_CLIENT)

$(NAME_SERVER):
	$(CC) $(CFLAGS) $(SRC_SERVER) -L. -lftprintf -o $(NAME_SERVER)

clean:
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

fclean: clean

re: fclean all
