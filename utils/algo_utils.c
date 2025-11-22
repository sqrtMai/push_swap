/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:12:36 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/22 11:45:24 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bring_cheapest_at_top(t_list **c, t_list **a, t_list **b)
{
	if ((*c)->target_node->above_median == true && (*c)->above_median == true)
	{
		while (*a != (*c)->target_node && *b != (*c))
			rr(a, b);
	}
	if ((*c)->target_node->above_median == false && (*c)->above_median == false)
	{
		while (*a != (*c)->target_node && *b != (*c))
			rrr(a, b);
	}
	while (*a != (*c)->target_node)
	{
		if ((*c)->target_node->above_median == false)
			reverse_rotate(a, 'a');
		else
			rotate(a, 'a');
	}
	while (*b != (*c))
	{
		if ((*c)->above_median == false)
			reverse_rotate(b, 'b');
		else
			rotate(b, 'b');
	}
}

void	find_cheapest(t_list **a, t_list **b)
{
	t_list	*actual_cheapest;
	t_list	*temp;
	int		price;

	temp = *b;
	actual_cheapest = temp;
	price = INT_MAX;
	while (temp)
	{
		if ((temp->push_cost) < price)
		{
			price = temp->push_cost;
			actual_cheapest = temp;
			if (price == 0)
			{
				actual_cheapest->cheapest = true;
				bring_cheapest_at_top(&actual_cheapest, a, b);
				return ;
			}
		}
		temp = temp->next;
	}
	actual_cheapest->cheapest = true;
	bring_cheapest_at_top(&actual_cheapest, a, b);
}

t_list	*smallest_bigger(t_list *a, t_list *b)
{
	long	difference;
	t_list	*temp;
	t_list	*smallest_bigger;

	temp = a;
	smallest_bigger = a;
	difference = INT_MAX;
	while (temp)
	{
		if ((temp->nbr - b->nbr > 0) && (temp->nbr - b->nbr < difference))
		{
			difference = temp->nbr - b->nbr;
			smallest_bigger = temp;
		}
		temp = temp->next;
	}
	return (smallest_bigger);
}

void	attribute_push_cost(t_list **a, t_list **b)
{
	int		len_b;
	int		len_a;
	t_list	*temp;

	len_a = ft_lstsize(*a);
	len_b = ft_lstsize(*b);
	temp = *b;
	while (temp)
	{
		temp->push_cost = temp->index;
		if (temp->above_median == false)
			temp->push_cost = len_b - temp->index;
		if (temp->target_node->above_median == false)
			temp->push_cost += len_a - temp->target_node->index;
		else
			temp->push_cost += temp->target_node->index;
		temp = temp->next;
	}
}

void	attribute_targets(t_list **a, t_list **b)
{
	t_list	*b_head;
	t_list	*a_head;

	b_head = *b;
	a_head = *a;
	while (*b)
	{
		if (is_max(a_head, *b))
			(*b)->target_node = find_min(a_head);
		else
			(*b)->target_node = smallest_bigger(a_head, *b);
		*b = (*b)->next;
	}
	*b = b_head;
}
