#include "push_swap.h"

int str_len(char **argv)
{
	int i = 0;
	while (argv[i])
		i++;
	return i - 1;
}

int find_index(int content, int *temp_sorted, int size)
{
	int i;
	i = 0;

	while (i < size - 1)
	{
		if (content == temp_sorted[i])
			return i;
		i++;
	}
	return i;
}
