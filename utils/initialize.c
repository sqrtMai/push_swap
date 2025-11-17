#include "../include/push_swap.h"

void current_index(f_list *stack)
{
	int i;
	int median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}


static void init_stack_a(char **argv, f_list **head)
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

void init_stacks(f_list **a, char **argv)
{
	init_stack_a(argv, a);
	current_index(*a);
}
