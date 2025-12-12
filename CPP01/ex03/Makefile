CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = unnecessary_violence

SRCS = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
OBJS = $(SRCS.cpp=.o)

all: $(NAME)

$(NAME): 
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
