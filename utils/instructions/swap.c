#include "../../include/push_swap.h"

void sa(f_list **head, int i)
{
	f_list *head_copy;
	f_list *temp;
	f_list *third;
	third = (*head)->next->next;

	temp = *head;
	head_copy = *head;

	*head = (*head)->next;
	(*head)->previous = NULL;
	(*head)->next = temp;
	temp->previous = (*head);
	temp->next = third;
	if (third)
		temp->next->previous = temp;
	current_index(*head);
	//temp->next->previous = NULL;
	//temp->next = *head;
	if (i == 1)
		write(1, "sa\n", 3);
}

void sb(f_list **head, int i)
{
	f_list *head_copy;
	f_list *temp;
	f_list *third;
	third = (*head)->next->next;

	temp = *head;
	head_copy = *head;

	*head = (*head)->next;
	(*head)->previous = NULL;
	(*head)->next = temp;
	temp->previous = (*head);
	temp->next = third;
	if (third)
		temp->next->previous = temp;
	current_index(*head);

	if (i == 1)
		write(1, "sb\n", 3);
}


void ss(f_list **a, f_list **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
