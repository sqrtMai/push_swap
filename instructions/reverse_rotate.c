/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:12:36 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/22 11:42:08 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_list **head, char c)
{
	t_list	*last;
	t_list	*before_last;

	last = ft_lstlast(*head);
	last->next = *head;
	before_last = last->previous;
	before_last->next = NULL;
	last->previous = NULL;
	(*head)->previous = last;
	*head = last;
	current_index(*head);
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a, 'c');
	reverse_rotate(b, 'c');
	write(1, "rrr\n", 4);
}
