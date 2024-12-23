NAME = libftprintf.a
SOURCES = ft_c.s.c ft_d_i_u.c ft_printf.c ft_x_X_p.c main.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
AR = ar

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $?

%.o: %.c
	$(CC) -c $?

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
