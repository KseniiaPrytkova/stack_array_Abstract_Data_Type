#include "../incs/stack_array_adt.h"

/* first element (argv[1] must be at the top of the stack (must come last)
- based on the task - that's why we will start filling the stack from 
the last element of input parameters (argv's))
*/

void red()
{
  printf("\033[1;31m");
}

void reset()
{
  printf("\033[0m");
}

void Fill_up_stack(t_stack *stack, char *argv[])
{
	int i;

	i = stack->max_size;
	while(i > 0 )
	{
		if(!(Push_to_stack(stack, atoi(argv[i]))))
			exit (0);
		i--;
	}
}

/* dubbuging fuction; if you want to empty the stack */
void Fill_up_empty_stack(t_stack *stack)
{
	int i;

	i = stack->max_size;
	while(i >= 0 )
	{
		stack->array[i] = 0;
		i--;
	}
}

/* again, first element (argv[1] must be at the top of the stack
(must come last), will print top element first)
*/
void Print_stack(t_stack *stack)
{
	int i;

	i = stack->max_size;
	while(i >= 0)
	{
		printf("%d\n", stack->array[i]);
		i--;
	}
}

/* TOP element will be colored in red */
void Print_two_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = stack_a->max_size - 1;
	while(i >= 0)
	{
		if (i == stack_a->counter - 1)
		{
			red();
			printf("%12d", stack_a->array[i]);
			reset();
		}
		else
			printf("%12d", stack_a->array[i]);

		if (i == stack_b->counter - 1)
		{
			red();
			printf("%20d\n", stack_b->array[i]);
			reset();
		}
		else
			printf("%20d\n", stack_b->array[i]);
		i--;
	}
	printf("%12s %19s\n", "-", "-" );
	printf("%12s %19s\n", "a", "b" );
}

void Print_stacks_info(t_stack *stack_a, t_stack *stack_b)
{
	printf("\n------------------------------\n");
	printf("|%17s %10s|\n", "|S_A", "S_B");
	printf("------------------------------\n");
	printf("counter: %7d %10d\n",stack_a->counter, stack_b->counter);
	printf("top: %11d %10d\n",stack_a->top, stack_b->top);
	printf("max_size: %6d %10d\n",stack_a->max_size, stack_b->max_size);
	if (stack_a->counter == 0)
	{	
		red();
		printf("top_val: %7c", 'e');
		reset();
	}
	else
		printf("top_val: %7d", Top_stack(stack_a));

	if (stack_b->counter == 0)
	{
		red();
		printf("%11c", 'e');
		reset();
	}
	else
		printf("%11d", Top_stack(stack_b));
	printf("\n");
	printf("------------------------------\n\n");
	Print_two_stacks(stack_a, stack_b);
}
