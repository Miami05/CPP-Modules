CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = fixed

SRCS = Fixed.cpp main.cpp
OBJCS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJCS)
	$(CXX) $(CXXFLAGS) $(OBJCS) -o $(NAME)

clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
