/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:12:36 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/22 11:43:11 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!argv[i][j])
			return (0);
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

int	check_doublon(t_list *a)
{
	t_list	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->nbr == temp->nbr)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

int	hay_overflow(char **argv)
{
	int			i;
	long long	n;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	check_sorted(t_list *head)
{
	int	i;

	i = 0;
	while (head->next)
	{
		if ((head)->nbr > (head)->next->nbr)
			return (0);
		head = (head)->next;
		i++;
	}
	return (1);
}

int	check_all_errors(char **argv)
{
	if (!is_valid(argv) || hay_overflow(argv))
		return (0);
	return (1);
}
