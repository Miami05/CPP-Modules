CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = account
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
