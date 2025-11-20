/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouarab <bbouarab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:23:46 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/20 09:43:01 by bbouarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

f_list	*ft_lstnew_ps(int content)
{
	f_list	*new_list;

	new_list = malloc(sizeof(f_list));

	if (!new_list)
		return (NULL);

	new_list->nbr = content;
	new_list->index = 0;
	new_list->push_cost = 0;
	new_list->above_median = NULL;
	new_list->cheapest = NULL;

	new_list->target_node = NULL;
	new_list->next = NULL;
	new_list->previous = NULL;

	return (new_list);
}
