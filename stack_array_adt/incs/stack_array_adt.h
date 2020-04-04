/* INTERFACE IMPLEMENTATION: STACK IS AN ARRAY */
/* prototypes of functions, that support stack-array operations */

#ifndef STACK_ARRAY_ADT_H
#define STACK_ARRAY_ADT_H
// #include "../../libft/incs/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

/* A structure to represent a stack */
typedef struct		s_stack 
{
	int				counter;
	int				top;
	int				max_size;
	int				*array;
}					t_stack;

void red();
void reset();
/* BASIC FUNCTION'S PROTOTYPES
	.
	.
	. */

/* ================== Create_stack ==================
Function creates an empty stack by allocating the head structure
and the array of integers from dynamic memory.
Pre: size - max number of elements in the stack. 
Post: returns pointer to stack head structure or NULL if overflow.
*/
t_stack *Create_stack(int	size);

/* ================== Destroy_stack ==================
Function releases all memory to the heap;
Pre: stack is pointer to stack head structure.
Post: returns null pointer.
*/
t_stack *Destroy_stack(t_stack *stack);

/* ================== Push_to_stack ==================
Function pushes an item onto the stack.
Pre: stack is pointer to stack head structure.
-data- is an integer to be inserted;
Post: it increases -top- by 1; returns TRUE if success; FALSE if overflow.
*/
int Push_to_stack(t_stack *stack, int data_in);

/* =================== Pop_from_stack ==================
This function pops the item on the top of the stack.
(removes an item from stack).
Pre: stack is pointer to stack head structure.
Post: decreases top by 1; returns integer if successful; 
NULL if underflow.
*/
int Pop_from_stack(t_stack *stack);


/* =================== Top_stack ==================
This function retrieves the data from the top of the stack without changing the stack.
Pre: stack is pointer to the stack.
Post: returns integer if successful.
*/
int Top_stack(t_stack *stack);

/* =================== Is_stack_full ==================
This function determines if a stack is full.
Pre: stack is a pointer to a stack head structure.
Post: returns true if full; false if empty elements
*/
int Is_stack_full(t_stack *stack);

/* =================== Is_stack_empty ==================
This function determines if a stack is empty.
Pre: stack is a pointer to the stack.
Post: returns true if empty; false if data in stack.
*/
int Is_stack_empty(t_stack *stack);

/* =================== Count_stack ==================
Returns number of elements in stack.
Pre: stack is a pointer to the stack.
Post: count returned.
*/
int Count_stack(t_stack *stack);

int Get_stack_size(t_stack*);

/* ADDITIONAL FUNCTION'S PROTOTYPES
	.
	.
	. */
void Fill_up_stack(t_stack *stack, char *argv[]);
void Fill_up_empty_stack(t_stack *stack);
void Print_stack(t_stack *stack);
void Print_two_stacks(t_stack *stack_a, t_stack *stack_b);
void Print_stacks_info(t_stack *stack_a, t_stack *stack_b);
int Check_integer_lims(int argc, char *argv[]);
int If_valid_integer(int argc, char *argv[]);
int Check_for_duplicates(int argc, char *argv[]);
void Check_input(int argc, char *argv[]);
char			*ft_itoa(int n);

#endif
