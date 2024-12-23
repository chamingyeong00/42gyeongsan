NAME = libftprintf.a
SOURCES = ft_c_s.c ft_d_i_u.c ft_printf.c ft_x_X_p.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
AR = ar

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $(OBJECTS)

%.o: %.c
	$(CC) -c $< -o $@ # $< 현재 소스 파일

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
