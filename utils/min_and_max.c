/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_and_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:12:36 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/22 11:43:24 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*find_max(t_list *stack)
{
	t_list	*temp;
	t_list	*current_max;
	int		i;

	temp = stack;
	i = temp->nbr;
	current_max = temp;
	while (temp)
	{
		if (temp->nbr > i)
		{
			i = temp->nbr;
			current_max = temp;
		}
		temp = temp->next;
	}
	return (current_max);
}

t_list	*find_min(t_list *stack)
{
	t_list	*temp;
	t_list	*current_min;
	int		i;

	temp = stack;
	i = temp->nbr;
	current_min = temp;
	while (temp)
	{
		if (temp->nbr < i)
		{
			i = temp->nbr;
			current_min = temp;
		}
		temp = temp->next;
	}
	return (current_min);
}

int	is_max(t_list *a, t_list *b)
{
	t_list	*temp;

	temp = a;
	while (temp)
	{
		if (temp->nbr > b->nbr)
			return (0);
		temp = temp->next;
	}
	return (1);
}
