NAME = gnl.out
cc = gcc
AR = ar rc
RM	= rm -r
LIBFT = libft
CFLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address -g3
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all
HEADER  = ../includes/
SRC_DIR = srcs/ft_

#files
SRC_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c
#rules

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(SRC_FILES)

OBJF = .cache_exists

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)
bonus : re
	@echo "bonus compiled"

out: re
	@./a.out

sanitize:
	$(CC) $(SANITIZE) $(SRC_FILES)
	@./a.out

valgrind: re
	@$(VALGRIND) ./a.out

clean:
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@$(RM) -f $(NAME)
	@$(RM) -f $(LIBFT)/libft.a

re: fclean all
