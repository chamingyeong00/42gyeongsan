NAME = animals

C++ = c++
C++FLAGS = -Wall -Wextra -Werror -std=c++98 -I inc

SRCS = src/main.cpp \
       src/Animal.cpp \
       src/Dog.cpp \
       src/Cat.cpp \
       src/WrongAnimal.cpp \
       src/WrongCat.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)

src/%.o: src/%.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re