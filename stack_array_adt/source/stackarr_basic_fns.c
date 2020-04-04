/* INTERFACE IMPLEMENTATION: STACK IS AN ARRAY OF INTEGERS */
/* If a stack’s maximum size can be calculated before the program is written,
an array implementation of a stack is more efficient than the dynamic
implementation using a linked list. */

#include "../incs/stack_array_adt.h"

/* 
============== FUNCTIONS, THAT SUPPORT STACK-ARRAY OPERATIONS ==============
 */

t_stack *Create_stack(int	size)
{
	t_stack *stack;

	stack = NULL;
	if (size <= 1)
	{
		// printf("Error: give me an array of numbers as an argument!\n");
		exit(0);
	}
	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
	{
		printf("Error: Bad malloc (Create_stack() - structure)\n");
		return (NULL);
	}
	stack->counter = 0;
	/*
	Because the newly created stack is by definition empty,
	we set the stack top index to –1. We must use –1 as the value for a
	null stack because a stack with only one item in it has a stack top of zero.
	*/
	stack->top = -1;
	stack->max_size = size;
	if (!(stack->array = (int *)malloc(sizeof(int) * (size +1 ))))
	{
		printf("Error: Bad malloc (Create_stack() - array)\n");
		free (stack);
		return (NULL);
	}
	return (stack);
}

t_stack *Destroy_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->array);
		free(stack);
	}
	return (NULL);
}

int Push_to_stack(t_stack *stack, int data_in)
{
	if (stack->counter == stack->max_size)
	{
		printf("Error: stack is overflow (Push_to_stack())\n");
		return (FALSE);
	}
	(stack->counter)++;
	(stack->top)++;
	stack->array[stack->top] = data_in;
	return (TRUE);
}

int Pop_from_stack(t_stack *stack)
{
	int data_out;

	data_out = 0;
	if (stack->counter == 0)
	{
		printf("Error: stack is underflow (Pop_from_stack())\n");
		exit(0);
		// // think about additional chech in thos case
		// return (FALSE);
	}
	else
	{
		data_out = stack->array[stack->top];
		(stack->counter)--;
		(stack->top)--;
	}
	return (data_out);
}

int Top_stack(t_stack *stack)
{
	if (stack->counter == 0)
	{
		printf("Error: stack is underflow (Top_stack())\n");
		exit(0);
	}
	else
		return (stack->array[stack->top]);
}

int Is_stack_full(t_stack *stack)
{
	if (stack->top == stack->max_size - 1)
		return (TRUE);
	else
		return (FALSE);
}

int Is_stack_empty(t_stack *stack)
{
	if (stack->counter == 0 && stack->top == -1)
		return (TRUE);
	else
		return (FALSE);
}

int Count_stack(t_stack *stack)
{
	return (stack->counter);
}

int Get_stack_size(t_stack *stack)
{
    return (stack->max_size);
}
