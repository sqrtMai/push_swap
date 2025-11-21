/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouarab <bbouarab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:12:34 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/21 09:17:28 by bbouarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void current_index(f_list *stack)
{
	int i;
	int median;

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


static void init_stack_a(int argc, char **argv, f_list **head)
{
	size_t i;
	//int size;

	i = 1;
	//size = str_len(argv);
	//int *temp_sorted = bubble_sort(argv);
	while (argv[i])
	{
		ft_lstadd_back_ps(head, ft_lstnew_ps((int)ft_atol(argv[i])));
		i++;
	}
}

void init_stacks(f_list **a, int argc, char **argv)
{
	init_stack_a(argc, argv, a);
	current_index(*a);
}
