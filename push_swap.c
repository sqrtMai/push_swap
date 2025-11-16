#include "push_swap.h"

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

int check_sorted(f_list *head, char **argv)
{
	int *temp_sorted = bubble_sort(argv);
	int i = 0;

	while ((head))
	{
		if ((head)->nbr != temp_sorted[i])
			return 0;
		head = (head)->next;
		i++;
	}
	return 1;
}

void sa(f_list **stack_a)
{
	f_list *temp;
	f_list *third;
	third = (*stack_a)->next->next;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp->next = third;

	write(1, "sa\n", 3);
}

void sa_triple(f_list ***stack_a)
{
	f_list *temp;

	temp = **stack_a;
	**stack_a = (**stack_a)->next;
	(**stack_a)->next = temp;
	write(1, "sa_t\n", 5);
}

void rra(f_list **a)
{
	f_list *temp;
	temp = *a;
	*a = (*a)->next->next;
	(*a)->next->next = temp;
	*a = (*a)->next;
	(*a)->next = temp;
	write(1, "rra\n", 4);
}

void tiny_sort(f_list **a, char **argv)
{
	write(1, "tu rentres dans le sort\n", 25);
	if ((*a)->nbr > (*a)->next->nbr)//if not sorted: if a > b : sa
		sa(a);
	if (!check_sorted(*a, argv))
		rra(a);
	// if (!check_sorted(*a, argv))
	// 	sa_triple(&(*&a));
	//Gg c'est sorted
}

int main(int argc, char **argv)
{
	f_list *stack_b;
	f_list *head_a;
	f_list *head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		return (1);
	if (!(check_all_errors(argv)))
		return error_print();
	init_stack_a(argv, &head_a);
	f_list **stack_a = &head_a;
	if (!check_sorted(head_a, argv))
	{
		if (str_len(argv) == 2)
			sa(&head_a);
		else if (str_len(argv) == 3)
			tiny_sort(&head_a, argv);
		// else
		// 	push_swap(&head_a, &head_b);
	}
	printf("\n%d - ", head_a->nbr);
	printf("%d - ", head_a->next->nbr);
	printf("%d", head_a->next->next->nbr);

	return 0;
}
