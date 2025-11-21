#include "../include/push_swap.h"


int error_print(void)
{
	return (write(2, "error\n", 6), 0);
}

int	is_valid(char **argv)
{
	int i;
	int j;

	i = 1;

	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
            j++;
        if (!argv[i][j])
            return 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int check_doublon(f_list *a)
{
	f_list *temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->nbr == temp->nbr)
				return 1;
			temp = temp->next;
		}
		a = a->next;
	}
	return 0;
}

// int check_doublon(char **argv)
// {
// 	int i;
// 	int j;

// 	i = 1;
// 	while(argv[i])
// 	{
// 		j = i + 1;
// 		while (argv[j])
// 		{
// 			if (ft_atol(argv[i]) == ft_atol(argv[i + j]))
// 				return 1;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return 0;


int hay_overflow(char **argv)
{
	int i;
	long long n;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			return 1;
		i++;
	}
	return 0;
}

int check_sorted(f_list *head, char **argv)
{
	//int *temp_sorted = bubble_sort(argv);
	int i = 0;

	while (head->next)
	{
		if ((head)->nbr > (head)->next->nbr)
			return 0;
		head = (head)->next;
		i++;
	}
	return 1;
}

int check_all_errors(char **argv)
{
	if (!is_valid(argv) || hay_overflow(argv))
		return (0);
	return 1;

}
