CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS_DIR = objs
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)
NAME = zombie
DEPS = $(OBJS:%.o=%.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
fclean: clean
	rm -f $(NAME)

re: fclean all
-include $(DEPS)
.PHONY: all clean fclean re

