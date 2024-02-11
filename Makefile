NAME_CLIENT = client
NAME_SERVER = server
LIBFTPRINTF = lib/printf
LIBFT = lib/libft
HASH_TABLE = lib/hash_table

LIBFTPRINTF_A = $(LIBFTPRINTF)/libftprintf.a
LIBFT_A = $(LIBFT)/libft.a
HASH_TABLE_A = $(HASH_TABLE)/hash_table.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_CLIENT = client.c
SRC_SERVER = server.c server_utils.c

LIBS = $(LIBFTPRINTF_A) $(LIBFT_A) $(HASH_TABLE_A)

all: compile_srcs $(NAME_CLIENT) $(NAME_SERVER)

compile_srcs:
	$(MAKE) -C $(LIBFTPRINTF)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(HASH_TABLE)

$(NAME_CLIENT): $(LIBS)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBS) -o $(NAME_CLIENT)

$(NAME_SERVER): $(LIBS)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBS) -o $(NAME_SERVER)

clean:
	rm -f $(NAME_CLIENT).o $(NAME_SERVER).o

fclean: clean
	$(MAKE) -C $(LIBFTPRINTF) fclean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(HASH_TABLE) fclean

re: fclean all
