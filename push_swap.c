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

	while (head)
	{
		if (head->nbr != temp_sorted[i])
			return 0;
		head = head->next;
		i++;
	}
	return 1;
}


int main(int argc, char **argv)
{
	f_list *stack_a;
	f_list *stack_b;
	f_list *head_a;
	f_list *head_b;

	head_a = NULL;
	head_b = NULL;
	stack_a = head_a;
	if (argc == 1)
		return (0);
	if (!(check_all_errors(argv)))
		return error_print();
	init_stack_a(argv, &head_a);
	if (check_sorted(head_a, argv))
		return 0;
	if (str_len(argv) == 2 && !check_sorted(head_a, argv))
		return 0;
	if (str_len(argv) == 3 && !check_sorted(head_a, argv))
		return 0;




	return 0;
}
