CFLAGS = -Wall -Wextra -Werror

SRC_FILES = get_next_line.c get_next_line_utils.c

SRC_FILES_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ_FILES = $(SRC_FILES:.c=.o)

OBJ_FILES_BONUS = $(SRC_FILES_BONUS:.c=.o)

NAME = get_next_line.out

NAME_BONUS = get_next_line_bonus.out

all: $(NAME)

$(NAME): $(OBJ_FILES)
			$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)


bonus: $(OBJ_FILES_BONUS)
			$(CC) $(CFLAGS) $(OBJ_FILES_BONUS) -o $(NAME_BONUS)


%.o: %.c
	@echo "compiling $<"
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	@echo "Cleaning up..."
	rm -f $(OBJ_FILES) $(OBJ_FILES_BONUS)
	
fclean :clean
	rm -f $(NAME)  $(NAME_BONUS)

re: fclean all 

.PHONY :all clean fclean re bonus