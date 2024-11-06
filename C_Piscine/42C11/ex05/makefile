CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
INC_DIR = includes
SRCS = $(SRC_DIR)/do_op.c $(SRC_DIR)/ft_atoi.c $(SRC_DIR)/ft_number_write.c $(SRC_DIR)/ft_operation.c
INCS = $(INC_DIR)/do_op.h $(INC_DIR)/ft_atoi.h $(INC_DIR)/ft_number_write.h $(INC_DIR)/ft_operation.h
OBJS	= ${SRCS:.c=.o}

NAME	= do-op
RM		= rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re