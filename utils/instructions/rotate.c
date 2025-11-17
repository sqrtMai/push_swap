#include "../../include/push_swap.h"

void rotate(f_list **head, char c)
{
	f_list *temp;
	f_list *head_copy;

	head_copy = *head;
	temp = *head;

	while (temp->next)
		temp = temp->next;

	*head = temp;
	temp->previous->next = NULL;
	temp->previous = NULL;
	temp->next = head_copy;

	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void rr(f_list **a, f_list **b)
{
	rotate(a, 'c');
	rotate(b, 'c');
	write(1, "rr\n", 3);
}
