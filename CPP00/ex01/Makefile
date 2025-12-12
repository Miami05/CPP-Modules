CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#Files
NAME = phonebook
SRC = contact.cpp phonebook.cpp main.cpp

# Default Target
all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
