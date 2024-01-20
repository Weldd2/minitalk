NAME = hash_table.a
HEADER = hash_table.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = hash_table.c hash_table_default.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all
