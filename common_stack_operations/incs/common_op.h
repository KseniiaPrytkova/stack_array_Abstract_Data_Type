/* prototypes of functions, that support PUSH_SWAP operations */

#ifndef COMMON_OP_H
#define COMMON_OP_H
#include <stdio.h>
#include <stdlib.h>
#include "../../stack_array_adt/incs/stack_array_adt.h"

#define TRUE 1
#define FALSE 0

void print_stacks_info(t_stack *stack_a, t_stack *stack_b);

/* PROTOTYPES OF FUNCTIONS, THAT REPRESENT PUSH_SWAP OPERATIONS
	.
	.
	. */
/*
	a - stack a;
	b - stack b
*/

/* OPERATION: sa / sb : swap stack */
/* RESULT: swap the first 2 elements at the top of stack.
Do nothing if there is only one or no elements). */
t_stack *swap(t_stack *stack);

/* OPERATION: ss : sa && sb */
/* RESULT: swap a and swap b at the same time.
Do nothing if there is only one or no elements). */
int swap_ab(t_stack *stack_a, t_stack *stack_b);

/* OPERATION: pa / pb : push a / b */
/* RESULT: take the first element at the top of a/b and put it at the top of b/a respectively.
Do nothing if a is empty */
int push(t_stack *stack_a, t_stack *stack_b);

/* OPERATION: ra / rb : rotate a / b */
/* RESULT: shift up all elements of stack by 1.
The first element becomes the last one. */
t_stack *rotate(t_stack *stack);

/* OPERATION: rr : ra && rb */
/* RESULT: rotate a and rotate b at the same time. */
int rotate_ab(t_stack *stack_a, t_stack *stack_b);

/* OPERATION: rra / rrb : reverse rotate a / b */
/* RESULT: - shift down all elements of stack by 1.
The last element becomes the first one. */
t_stack *reverse_rotate(t_stack *stack);

/* OPERATION: rrr : rra && rrb */
/* RESULT: -  everse rotate a and reverse rotate b at the same time. */
int reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);

#endif
