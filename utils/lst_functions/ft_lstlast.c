/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouarab <bbouarab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:20:49 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/17 14:19:11 by bbouarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/push_swap.h"

f_list	*ft_lstlast(f_list *lst)
{
	f_list	*temp;

	if (!lst)
		return (lst);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
