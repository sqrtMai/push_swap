#include "../include/push_swap.h"

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

static int *bubble_sort(char **argv, int argc)
{
	int *copy;
	int i;
	int j;
	int temp;
	int size;

	i = 0;
	copy = intdup(argv);
	size = argc - 1;
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
int check_if_median(t_list *b, char **argv, int argc)
{
	int *sorted = bubble_sort(argv, argc);
	int i = 0;
	int median = (argc - 1) / 2;

	while (i != argc - 1)
	{
		if (b->nbr == sorted[i])
		{
			if (i <= median)
				return 1;
			else
				return 0;
		}
		i++;
	}
	return -1;
}
