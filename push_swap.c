#include "include/push_swap.h"

void tiny_sort(f_list **a, char **argv)
{
	write(1, "tu rentres dans le sort\n", 25);
	if ((*a)->nbr > (*a)->next->nbr) // if not sorted: if a > b : sa
		sa(a, 1);
	if (!check_sorted(*a, argv))
		reverse_rotate(a, 'a');
	if (!check_sorted(*a, argv))
		sa(a, 1);
}

void push_swap(f_list **a, f_list **b, char **argv)
{
	int len_a;

	len_a = ft_lstsize(*a);
	while (len_a != 3)
	{
		pb(a, b);
		len_a--;
	}
	tiny_sort(a, argv);
}

int main(int argc, char **argv)
{
	f_list *head_a;
	f_list *head_b;
	f_list **stack_a = &head_a;
	f_list **stack_b = &head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		return (1);
	if (!(check_all_errors(argv)))
		return error_print();
	init_stacks(&head_a, argv);
	// printf("\n%d - ", head_a->index);
	// printf("%d - ", head_a->next->index);
	// printf("%d", head_a->next->next->index);
	if (!check_sorted(head_a, argv))
	{
		if (str_len(argv) == 2)
			sa(&head_a, 1);
		else if (str_len(argv) == 3)
			tiny_sort(stack_a, argv);
		else
			push_swap(stack_a, stack_b, argv);
	}

	return 0;
}
