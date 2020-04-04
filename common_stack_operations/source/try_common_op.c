/* RUN ME: 
$ gcc *.c ../stack_array_adt/./stackarr.a
$ leaks -atExit --quiet -- ./a.out 5 6 7 8 9
from /push_swap_OPERATIONS folder

after creating a library:
$ make
$ gcc source/try_common_op.c ./stackopp.a ../stack_array_adt/./stackarr.a
*/
#include "../incs/common_op.h"

int main(int argc, char const *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;

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
	printf("\nPUSH\n");
	if (!(push(stack_a, stack_b)))
		printf("Error: push()\n");
	if (!(push(stack_b, stack_a)))
		printf("Error: push()\n");
	Print_stacks_info(stack_a, stack_b);

/* ================== check swap ops ==================
*/
	printf("\nSWAP\n");
	if (!(swap(stack_a)))
	{
		printf("Error: Stack a doesn't exist! (swap())\n");
	}
	print_stacks_info(stack_a, stack_b);
	if (!(swap_ab(stack_a, stack_b)))
	{
		printf("Error: Stacks do not exist! (swap_ab())\n");
	}
	print_stacks_info(stack_a, stack_b);

/* ================== check rotate ops ==================
*/
	printf("\nROTATE\n");
	if (!(reverse_rotate(stack_a, stack_b)))
		printf("Error: rotate_b()\n");
	Print_stacks_info(stack_a, stack_b);

	if (Destroy_stack(stack_a) || Destroy_stack(stack_b))
		printf("Error: Can't destroy stack!\n");
	return (0);
}
