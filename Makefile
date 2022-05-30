NAME = gnl.out
cc = gcc
AR = ar rc
RM	= rm -r
LIBFT = libft
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42
TFLAGS = -std=c11 -Wall -ggdb3 -D BUFFER_SIZE=42
SANITIZE = -fsanitize=address -g3 -D BUFFER_SIZE=42
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

#files
BONUS_SRC_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c
SRC_FILES = get_next_line.c get_next_line_utils.c
#rules

bonus: re
	@$(CC) -o $(NAME) $(CFLAGS) $(BONUS_SRC_FILES)
	@echo "bonus compiled"

mandatory: re
	@$(CC) -o $(NAME) $(CFLAGS) $(SRC_FILES)
	@echo "mandatory compiled"
out:
	@clear
	@./$(NAME)
sanitize_bonus: re
	@$(CC) -o $(NAME) $(SANITIZE) $(BONUS_SRC_FILES)
	@./$(NAME)

sanitize_mandatory: re
	$(CC) -o $(NAME) $(SANITIZE) $(SRC_FILES)
	@./$(NAME)

valgrind_mandatory: re
	@$(CC) -o $(NAME) $(TFLAGS) $(SRC_FILES)
	@$(VALGRIND) ./$(NAME)

valgrind_bonus: re
	@$(CC)  $(TFLAGS) $(BONUS_SRC_FILES) -o $(NAME)
	@$(VALGRIND) ./$(NAME)

clean:
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@$(RM) -f $(NAME)

re: fclean
