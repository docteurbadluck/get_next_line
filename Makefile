CC = cc 
FLAGS = -Wall -Werror -Wextra
SRC = main.c get_next_line_utils.c
HEADER = get_next_line.h 
NAME = get_next_line.out

all: $(NAME)

$(NAME): 
	$(CC) $(SRC) $(FLAGS) -I . -o $@

fclean: 
	rm $(NAME)  -f

re:
	make fclean
	make

.PHONY : fclean re