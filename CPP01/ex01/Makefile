CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Zombie.cpp main.cpp zombieHorde.cpp

OBJ = $(SRCS:.cpp=.o)

NAME = horde

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
