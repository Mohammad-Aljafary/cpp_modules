CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp RPN.cpp
OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)
DEP = $(OBJ:%.o=%.d)
NAME = RPN

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)