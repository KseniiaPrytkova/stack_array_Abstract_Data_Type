.PHONY: all clean fclean re mclean mfclean mre

NAME = stackopp.a

# LIB_DIR = ../libft
# LIB_NAME = $(LIB_DIR)/libftprintf.a

INC1_DIR = ../stack_array_adt
INC1_NAME = $(INC1_DIR)/stackarr.a

OBJECT_PROJECT = $(SRC_PROJECT:.c=.o)
FLAGS = -O3 -Wall -Wextra -Werror -Iincs/
SRC_PROJECT =	source/common_op_push.c\
				source/common_op_swap.c\
				source/common_op_rotate.c\
				source/common_op_reverse_rotate.c\

all: $(NAME)

$(NAME): $(INC1_NAME) $(OBJECT_PROJECT)
	@ar rc $(NAME) $(OBJECT_PROJECT)
	@ranlib $(NAME)
	@echo "🍓  make $(NAME): done"

$(INC1_NAME):
	@make -C $(INC1_DIR)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<
	@echo "$(NAME): linking "[ $@ ]

clean:
	@/bin/rm -f $(OBJECT_PROJECT)
	@make -C ../stack_array_adt/ clean
	@echo "$(NAME): remove object files"

fclean:
	@/bin/rm -f $(OBJECT_PROJECT)
	@/bin/rm -f $(NAME)
	@make -C ../stack_array_adt/ fclean
	@echo "$(NAME): remove object and binary files"

re: fclean all
