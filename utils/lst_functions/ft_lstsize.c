/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouarab <bbouarab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:30:44 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/17 14:19:39 by bbouarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/push_swap.h"

int	ft_lstsize(f_list *lst)
{
	f_list	*temp;
	int		i;

	if (!lst)
		return (0);
	i = 1;
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
