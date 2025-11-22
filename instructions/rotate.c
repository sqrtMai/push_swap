/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:12:36 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/22 11:42:15 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_list **head, char c)
{
	t_list	*last;
	t_list	*head_copy;

	head_copy = (*head);
	last = ft_lstlast(*head);
	*head = (*head)->next;
	(*head)->previous = NULL;
	last->next = head_copy;
	head_copy->previous = last;
	head_copy->next = NULL;
	current_index(*head);
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a, 'c');
	rotate(b, 'c');
	write(1, "rr\n", 3);
}
