# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeham <yeham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 19:26:28 by yeham             #+#    #+#              #
#    Updated: 2022/12/03 13:55:30 by yeham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipe.c ft_split2.c 

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cc $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean :
	$(MAKE) -C ./libft fclean
	make clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re