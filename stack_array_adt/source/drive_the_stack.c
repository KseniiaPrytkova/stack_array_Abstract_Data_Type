/* RUN ME: gcc ./source/drive_the_stack.c ./stackarr.a
from /stack_array_ADT folder
*/
#include "../incs/stack_array_adt.h"

int main(int argc, char const *argv[])
{
	t_stack *stack;

	stack = NULL;
	if (!(stack = Create_stack(argc - 1)))
		exit(0);
	Fill_up_stack(stack, argv);
	Print_stack(stack);
	printf("top--->%d\n", Top_stack(stack));
	printf("pop--->%d\n", Pop_from_stack(stack));
	if (Is_stack_full(stack))
		printf("FULL\n");
	else
		printf("NOT FULL\n");

	if (Is_stack_empty(stack))
		printf("EMPTY\n");
	else
		printf("NOT EMPTY\n");
	printf("count = %d\n", Count_stack(stack));
	printf("stack_counter = %d\nstack_top = %d\nstack_max_size = %d\n", stack->counter, stack->top, stack->max_size);
	Destroy_stack(stack);
	return (0);
}
