#include "../include/push_swap.h"

void pa(f_list **a, f_list **b)
{
	f_list *copy;
	f_list *copy_a;

	copy = *b;
	copy_a = *a;
	if (*b)
	{
		*b = (*b)->next;
		if (*b)
			(*b)->previous = NULL;
		copy->next = (*a);
		if (*a)
			(*a)->previous = copy;
		*a = copy;
		current_index(*a);
		current_index(*b);
	}

	write(1, "pa\n", 3);
}

void pb(f_list **a, f_list **b)
{
	f_list *copy;
	f_list *copy_b;

	copy = *a;
	copy_b = *b;

	if (*a)
	{
		*a = (*a)->next;
		if (*a)
			(*a)->previous = NULL;
		copy->next = (*b);
		if (*b)
			(*b)->previous = copy;
		*b = copy;
	}
	current_index(*a);
	current_index(*b);

	write(1, "pb\n", 3);
}
