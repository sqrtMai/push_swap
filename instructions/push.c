/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:12:36 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/22 11:41:56 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*copy;

	copy = *b;
	if (*b)
	{
		*b = (*b)->next;
		if (*b)
			(*b)->previous = NULL;
		copy->next = (*a);
		if (*a)
			(*a)->previous = copy;
		*a = copy;
		current_index(*a);
		current_index(*b);
	}
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*copy;

	copy = *a;
	if (*a)
	{
		*a = (*a)->next;
		if (*a)
			(*a)->previous = NULL;
		copy->next = (*b);
		if (*b)
			(*b)->previous = copy;
		*b = copy;
	}
	current_index(*a);
	current_index(*b);
	write(1, "pb\n", 3);
}
