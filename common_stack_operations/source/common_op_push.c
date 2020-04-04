#include "../incs/common_op.h"

/* ================== PUSH OPERATIONS ==================
Take the first element at the top of one stack and put it at the top of another stack.
*/

/* pa / pb
*/
int push(t_stack *stack_a, t_stack *stack_b)
{
	int temp;

	temp = 0;
	if (!(stack_a) || !(stack_b))
		return (FALSE);
	if (!(Is_stack_empty(stack_b)))
	{
		temp = Pop_from_stack(stack_b);
		if (!(Push_to_stack(stack_a, temp)))
			return (FALSE);
		// else
		// 	return (TRUE);
	}
	else
		printf("DO NOTHING: stack is empty (push())\n");
	return (TRUE);
}
