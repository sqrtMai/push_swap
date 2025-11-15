#include "push_swap.h"

static int *intdup(char **argv)
{
	int i;
	int j;
	int *new_array;

	i = 1;
	while (argv[i])
		i++;
	new_array = malloc((i - 1) * sizeof(int));
	if (!new_array)
		return 0;
	i = 1;
	j = 0;
	while (argv[i])
		new_array[j++] = ft_atol(argv[i++]);
	return new_array;
}

int *bubble_sort(char **argv)
{
	int *copy;
	int i;
	int j;
	int temp;
	int size;

	i = 0;
	copy = intdup(argv);
	size = str_len(argv);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (copy[j] > copy[j + 1])
			{
				temp = copy[j];
				copy[j] = copy[j + 1];
				copy[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return copy;
}

