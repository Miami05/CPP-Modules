NAME := interface

CXX := c++

CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := AMateria.cpp Character.cpp main.cpp \
	   Ice.cpp Cure.cpp MateriaSource.cpp

OBJS := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
