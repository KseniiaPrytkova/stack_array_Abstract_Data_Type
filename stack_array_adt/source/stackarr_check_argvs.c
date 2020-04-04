#include "../incs/stack_array_adt.h"

int Check_integer_lims(int argc, char *argv[])
{
	int i;
	char *s_max;
	char *s_min;
	int ret;

	s_max = ft_itoa(INT_MAX);
	s_min = ft_itoa(INT_MIN);
	ret = -1;
	i = 1;
	while (i < argc && ret == -1)
	{
		if (strlen(argv[i]) == strlen(s_max))
		{
			if (argv[i][0] == '-')
				ret = TRUE;
			else if ((atoi(argv[i]) - INT_MAX) > 0)
				ret = FALSE;
		}
		else if (strlen(argv[i]) > strlen(s_max))
		{
			if ((argv[i][0] == '-') && (strlen(argv[i]) == strlen(s_min)))
			{
				if (((atoi(argv[i]) * -1) - INT_MIN) > 0)
					ret = FALSE;
				else
					ret = TRUE;
			}
			else
				ret = FALSE;
		}
		i++;
	}
	if (ret == -1)
		ret = TRUE;
	free(s_max);
	free(s_min);
	return (ret);
}

int If_valid_integer(int argc, char *argv[])
{
	int i;
	int j;
	int len;

	i = 1;
	j= 0;
	len = 0;
	while(i < argc)
	{
		len = strlen(argv[i]);
		if (argv[i][0] == '-')
			j = 1;
		else
			j = 0;
		while (j < len)
		{
			if (!(isdigit(argv[i][j])))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int Check_for_duplicates(int argc, char *argv[])
{
	int i;
	int j;
	int a;
	int b;

	i = 1;
	while(i < argc)
	{
		a = atoi(argv[i]);
		j = i + 1;
		while(j < argc)
		{
			b = atoi(argv[j]);
			if (!(a ^ b))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
