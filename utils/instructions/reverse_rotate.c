#include "../../include/push_swap.h"

void reverse_rotate(f_list **head, char c)
{
	f_list *last;
	f_list *new_last;
	f_list *before_last;

	last = ft_lstlast(*head);
	last->next = *head;

	before_last = last->previous;
	before_last->next = NULL;

	last->previous = NULL;
	(*head)->previous = last;
	*head = last;
	current_index(*head);

	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void rrr(f_list **a, f_list **b)
{
	reverse_rotate(a, 'c');
	reverse_rotate(b, 'c');
	write(1, "rrr\n", 4);
}
