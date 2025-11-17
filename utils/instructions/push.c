#include "../../include/push_swap.h"

void pa(f_list **a, f_list **b)
{
	f_list *copy;
	f_list *copy_a;

	copy = *b;
	copy_a = *a;
	*b = (*b)->next;
	(*b)->previous = NULL;

	*a = copy;
	(*a)->next = copy_a;
	write(1, "pa\n", 3);
}

void pb(f_list **a, f_list **b)
{
	f_list *copy;
	f_list *copy_b;

	copy = *a;
	copy_b = *b;
	*a = (*a)->next;
	(*a)->previous = NULL;

	*b = copy;
	(*a)->next = copy_b;
	write(1, "pb\n", 3);
}
