/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:12:34 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/22 11:43:17 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	current_index(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!(stack))
		return ;
	median = ft_lstsize((stack)) / 2;
	while ((stack))
	{
		(stack)->index = i;
		if (i <= (median))
			(stack)->above_median = true;
		else
			(stack)->above_median = false;
		(stack) = (stack)->next;
		i++;
	}
}

static void	init_stack_a(char **argv, t_list **head)
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		ft_lstadd_back_ps(head, ft_lstnew_ps((int)ft_atol(argv[i])));
		i++;
	}
}

void	init_stacks(t_list **a, char **argv)
{
	init_stack_a(argv, a);
	current_index(*a);
}
