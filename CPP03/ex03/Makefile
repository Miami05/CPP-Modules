NAME := diamondtraps
CXX := c++
SRC := ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp
OBJ := $(SRC:.cpp=.o)

CXXFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME)_shadow $(NAME)_noshadow

re: fclean all

shadow: fclean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -Wshadow" $(NAME)_shadow

noshadow: fclean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -Wno-shadow" $(NAME)_noshadow

$(NAME)_shadow: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(NAME)_noshadow: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: all clean fclean re shadow noshadow

