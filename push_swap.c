#include "push_swap.h"


void init_stack_a(char **argv, f_list **head)
{
	size_t i;

	i = 1;
	while (argv[i])
		ft_lstadd_back_ps(&head, ft_lstnew_ps(ft_atoi(argv[i++])));
}

int main(int argc, char **argv)
{
	f_list *head;

	head = NULL;
	if (argc == 1)
		return (0);
	if (!(check_all_errors(argv)))
		return error_print();

	init_stack_a(argv, &head);
}
