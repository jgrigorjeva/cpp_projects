# Compiler and flags
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

# Target
NAME     = test

# Source and object
SRC      = main.cpp Span.cpp
OBJ_DIR  = obj
OBJ      = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))
DEP      = $(patsubst %.cpp,$(OBJ_DIR)/%.d,$(SRC))

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Create object directory (if missing)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile rule: write .o into obj/ and .d into obj/
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -MF $(OBJ_DIR)/$*.d

clean:
	$(RM) $(OBJ) $(DEP)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re