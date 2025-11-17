#include "../include/push_swap.h"

f_list *find_min(f_list *lst, char **argv)
{
	int		i;
	int		*sorted_list;
	f_list	*temp;

	i = 0;
	sorted_list = bubble_sort(argv);
	temp = lst;
	while (i < str_len(argv))
	{
		while (temp)
		{
			if (temp->nbr == sorted_list[i])
				return temp;
			temp = temp->next;
		}
		i++;
		temp = lst;
	}
	return NULL;
}

f_list *find_max(f_list *lst, char **argv)
{
	int		i;
	int		*sorted_list;
	f_list	*temp;

	i = str_len(argv);
	sorted_list = bubble_sort(argv);
	temp = lst;
	while (i >= 0)
	{
		while (temp)
		{
			if (temp->nbr == sorted_list[i])
				return temp;
			temp = temp->next;
		}
		i--;
		temp = lst;
	}
	return NULL;
}
