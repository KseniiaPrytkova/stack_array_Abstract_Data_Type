.PHONY: all clean fclean re mclean mfclean mre

NAME = stackarr.a

FLAGS = -Wall -Wextra -Werror
DIR_S = source
DIR_O = temp
HEADER = incs
SOURCES = 	stackarr_basic_fns.c\
			stackarr_add_fns.c\
			stackarr_check_argvs.c\
			check_input.c\
			ft_itoa.c\

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "🍓  make $(NAME): done"

# $(LIB_NAME):
# 	@make -C $(LIB_DIR)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temp
	@echo "$(NAME): linking "[ $@ ]
	@gcc $(FLAGS) -I./$(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
# 	@make -C ../libft/ clean
	@echo "$(NAME): remove object files"

fclean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@/bin/rm -f $(NAME)
# 	@make -C ../libft/ fclean
	@echo "$(NAME): remove object and binary files"

re: fclean all
