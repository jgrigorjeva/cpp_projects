# Compiler and flags
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -MMD -MP 

# Target
NAME    = frag

# Source and object
SRC     = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ     = $(SRC:.cpp=.o)
DEP      = $(SRC:.cpp=.d)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re