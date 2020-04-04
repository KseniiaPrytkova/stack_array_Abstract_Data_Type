#include "../incs/common_op.h"

/* ================== REVERSE ROTATE OPERATIONS ==================
shift down all elements of stack a/b by 1 (the last element becomes the first one)
*/

/* rra / rrb
*/
t_stack *reverse_rotate(t_stack *stack)
{
	int temp;
	int i;

	temp = 0;
	i = 0;
	if (!stack)
		return (NULL);
	if (!(Is_stack_empty(stack)) && (stack->top > 0))
	{
		temp = stack->array[0];
		while(i < stack->counter - 1)
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[i] = temp;
	}
	return (stack);
}

/* rrr
*/
int reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	if (!(stack_a) || !(stack_b))
		return (FALSE);
	if (!(stack_a = reverse_rotate(stack_a)) || !(stack_b = reverse_rotate(stack_b)))
		return (FALSE);
	else
		return (TRUE);
}
