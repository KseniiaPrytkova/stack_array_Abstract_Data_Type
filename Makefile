# special targets are called phony and you can explicitly tell Make they're not
# associated with files (>make clean will run as expected even if
# you do have a file named clean)
.PHONY: all clean fclean re push_swap checker reclean

NAME = stack_lib
INC_DIR = common_stack_operations
INC_NAME = $(INC_DIR)/stackopp.a

SOURCE =	drive_stack.c\

OBJS = $(SOURCE:.c=.o)

FL = -Wall -Wextra
FLAGS = $(FL) common_stack_operations/stackopp.a stack_array_adt/stackarr.a

all: $(NAME)

$(NAME): $(INC_NAME)
	@echo '🍓 compiling stack_arr lib ...'
	@gcc -o $(NAME) $(FLAGS) $(SOURCE)
	@echo 'ready!'

$(INC_NAME):
	@make -C $(INC_DIR)

clean:
	@rm -f $(OBJS)
	@make -C $(INC_DIR) clean

fclean:
	@rm -f $(OBJS)
	@/bin/rm -f $(NAME)
	@make -C $(INC_DIR) fclean

re: fclean all
