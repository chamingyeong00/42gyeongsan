C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98
INFILES = 	main.cpp\
			Weapon.cpp\
			HumanA.cpp\
			HumanB.cpp\
			

OBJFILES = $(INFILES:.cpp=.o)

NAME = Unnecessary_violence

all: $(NAME)


$(NAME):$(OBJFILES)
	$(C++) $(C++_FLAGS) $(OBJFILES) -o $(NAME) 

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
