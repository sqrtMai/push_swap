#include "push_swap.h"



int *intdup(char **argv)
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

void init_stack_a(char **argv, f_list **head)
{
	size_t i;
	int size;

	i = 1;
	size = str_len(argv);
	int *temp_sorted = bubble_sort(argv);
	while (argv[i])
	{
		ft_lstadd_back_ps(&head, ft_lstnew_ps((int)ft_atol(argv[i]), temp_sorted, size));
		i++;
	}
}

int main(int argc, char **argv)
{
	f_list *head;

	head = NULL;
	if (argc == 1)
		return (0);
	if (!(check_all_errors(argv)))
		return error_print();
	init_stack_a(argv, &head);
	printf("%d", head->index);
	return 0;
}
