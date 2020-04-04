#include "../incs/common_op.h"

/* ================== SWAP OPERATIONS ==================
Swap the first two elements at the top of stack/stacks.
*/

/* sa / sb
*/
t_stack *swap(t_stack *stack)
{
	int temp;

	temp = 0;
	if (!stack)
		return (NULL);
	if (!(Is_stack_empty(stack)) && (stack->top > 0))
	{
		temp = stack->array[stack->top];
		stack->array[stack->top] = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = temp;
	}
	else
	{
		printf("DO NOTHING: in stack is one or no elements( swap() )\n");
	}
	return (stack);
}

/* ss
*/
int swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	if (!(stack_a) || !(stack_b))
		return (FALSE);
	if (!(stack_a = swap(stack_a)) || !(stack_b = swap(stack_b)))
		return (FALSE);
	else
		return (TRUE);
}
