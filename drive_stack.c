#include "common_stack_operations/incs/common_op.h"

int main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;

	Check_input(argc, argv);
/* ================== initial state ==================
create 2 stacks: a is filled with argv's; b is empty
*/
	if (!(stack_a = Create_stack(argc - 1))
		|| !(stack_b = Create_stack(argc - 1)))
		exit(0);
	Fill_up_stack(stack_a, argv);
	Fill_up_empty_stack(stack_b);
	Print_stacks_info(stack_a, stack_b);

/* ================== check push ops ==================
*/
	printf("\nP U S H\n");
	if (!(push(stack_b, stack_a)))
		printf("Error: push()\n");
	Print_stacks_info(stack_a, stack_b);

/* ================== destroy two stacks ==================
*/
	if (Destroy_stack(stack_a) || Destroy_stack(stack_b))
		printf("Error: Can't destroy stack!\n");
	return (0);
}
