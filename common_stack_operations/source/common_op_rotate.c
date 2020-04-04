#include "../incs/common_op.h"

/* ================== ROTATE OPERATIONS ==================
shift up all elements of stack a/b by 1 (the first element becomes the last one)
*/

/* ra / rb
*/
t_stack *rotate(t_stack *stack)
{
	int temp;
	int i;

	temp = 0;
	i = 0;
	if (!stack)
		return (NULL);
	if (!(Is_stack_empty(stack)) && (stack->top > 0))
	{
		temp = stack->array[stack->top];
		i = stack->counter;
		while(i > 0)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[i] = temp;
	}
	return (stack);
}

/* rr
*/
int rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	if (!(stack_a) || !(stack_b))
		return (FALSE);
	if (!(stack_a = rotate(stack_a)) || !(stack_b = rotate(stack_b)))
		return (FALSE);
	else
		return (TRUE);
}
