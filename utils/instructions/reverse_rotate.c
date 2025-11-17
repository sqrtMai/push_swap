#include "../../include/push_swap.h"

void reverse_rotate(f_list **head, char c)
{
	f_list *temp;
	f_list *head_copy;

	head_copy = *head;
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = head_copy;
	temp->previous->next = NULL;
	temp->previous = NULL;
	*head = temp;
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
