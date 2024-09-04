CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
INC_DIR = includes
SRCS = $(SRC_DIR)/bsq.c $(SRC_DIR)/main.c $(SRC_DIR)/map.c $(SRC_DIR)/util_map.c $(SRC_DIR)/util_str.c $(SRC_DIR)/util.c
OBJS = $(SRCS:.c=.o)
NAME = bsq

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -I $(INC_DIR) -c $< 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
