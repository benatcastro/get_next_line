NAME = gnl.out
cc = gcc
AR = ar rc
RM	= rm -r
LIBFT = libft
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42
TFLAGS = -std=c11 -Wall -ggdb3 -D BUFFER_SIZE=42
SANITIZE = -fsanitize=address -g3 -D BUFFER_SIZE=42
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
HEADER  = ../includes/
SRC_DIR = srcs/ft_

#files
SRC_FILES = get_next_line.c get_next_line_utils.c
#rules

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(CFLAGS) $(SRC_FILES)

OBJF = .cache_exists

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)
bonus : re
	@echo "bonus compiled"

out: re
	@clear
	@./a.out

sanitize:
	$(CC) $(SANITIZE) $(SRC_FILES)
	@./a.out

valgrind:
	@$(CC) $(TFLAGS) $(SRC_FILES)
	@$(VALGRIND) ./a.out

clean:
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@$(RM) -f $(NAME)
	@$(RM) -f $(LIBFT)/libft.a

re: fclean all
