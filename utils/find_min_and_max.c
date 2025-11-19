#include "../include/push_swap.h"

f_list *find_min(f_list **stack)
{
	int		i;
	f_list *temp;
	f_list *current_min;

	temp = *stack;
	i = temp->nbr;
	while (temp)
	{
		if (temp->nbr < i)
		{
			i = temp->nbr;
			current_min = temp;
		}
		temp = temp->next;
	}
	return current_min;
}

bool *is_max(f_list **a, f_list *b)
{
	/*en gros là tu dois comparer le node actuel de B avec TOUS les nodes de A
	et return si le node si jamais c'est le plus grand */
	int		i;
	f_list *temp;
	f_list *current_max;

	current_max = NULL;
	temp = *a;
	i = temp->nbr;
	while (temp)
	{
		if (temp->nbr > b->nbr)
			return false;
		temp = temp->next;
	}
	return true;
}
