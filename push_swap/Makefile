NAME = push_swap
SOURCES = push_swap.c check_error.c init_stack.c \
		push.c reverse_rotate.c rotate.c swap.c \
		radix_sort.c set_index.c check_error_utils.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $^ -L./libft -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

