NAME = harlFilter

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Harl.cpp main.cpp
OBJCS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJCS)
	$(CXX) $(CXXFLAGS) $(OBJCS) -o $(NAME)

clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean all
