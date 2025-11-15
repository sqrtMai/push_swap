/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_ps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:16:46 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/15 17:34:00 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_ps(f_list ***lst, f_list *new)
{
	f_list	*temp;

	if (!lst || !new)
		return ;
	if (!**lst)
	{
		**lst = new;
		return ;
	}
	temp = **lst;

	while (temp->next != NULL) // BOucle qui permet d'accéder au dernier node;
		temp = temp->next;

	temp->next = new;
	new->next = NULL;
	new->previous = temp;
}
