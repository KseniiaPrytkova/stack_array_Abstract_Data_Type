#include "../incs/stack_array_adt.h"

void Check_input(int argc, char *argv[])
{
	if (argc <= 1)
	{
		printf("Error: give me an array of numbers as an argument!\n");
		exit(0);
	}
	if (!(If_valid_integer(argc, argv)))
	{
		printf("Error. Argument contains not only digits.\n");
		exit (0);
	}
	if (!(Check_integer_lims(argc, argv)))
	{
		printf("Error. Argument is not in integer limits.\n");
		exit (0);
	}
	if (!(Check_for_duplicates(argc, argv)))
	{
		printf("Error. There are duplicates in array of ints.\n");
		exit (0);
	}
}
