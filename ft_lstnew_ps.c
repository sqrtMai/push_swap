/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:23:46 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/15 18:16:38 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



f_list	*ft_lstnew_ps(int content, int *temp_sorted, int size)
{
	f_list	*new_list;

	new_list = malloc(sizeof(f_list));

	if (!new_list)
		return (NULL);

	new_list->nbr = content;
	new_list->index = find_index(content, temp_sorted, size);
	new_list->push_cost = 0;
	new_list->above_median = NULL;
	new_list->cheapest = NULL;

	new_list->next = NULL;
	new_list->previous = NULL;

	return (new_list);
}
