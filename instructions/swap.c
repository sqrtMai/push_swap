/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:12:36 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/22 11:42:23 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_list **head, int i)
{
	t_list	*temp;
	t_list	*third;

	third = (*head)->next->next;
	temp = *head;
	*head = (*head)->next;
	(*head)->previous = NULL;
	(*head)->next = temp;
	temp->previous = (*head);
	temp->next = third;
	if (third)
		temp->next->previous = temp;
	current_index(*head);
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list **head, int i)
{
	t_list	*temp;
	t_list	*third;

	third = (*head)->next->next;
	temp = *head;
	*head = (*head)->next;
	(*head)->previous = NULL;
	(*head)->next = temp;
	temp->previous = (*head);
	temp->next = third;
	if (third)
		temp->next->previous = temp;
	current_index(*head);
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
