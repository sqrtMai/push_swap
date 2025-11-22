/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:12:36 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/22 14:01:29 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	error_print(void)
{
	return (write(2, "error\n", 6), 0);
}

static void	finish_sort(t_list **stack)
{
	if (find_min(*stack)->above_median == true)
	{
		while (*stack != find_min(*stack))
			rotate(stack, 'a');
	}
	else
	{
		while (*stack != find_min(*stack))
			reverse_rotate(stack, 'a');
	}
}

static void	tiny_sort(t_list **a)
{
	t_list	*biggest;

	biggest = find_max(*a);
	if ((*a) == biggest)
		rotate(a, 'a');
	else if ((*a)->next == biggest)
		reverse_rotate(a, 'a');
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
}

static void	push_swap(t_list **a, t_list **b, char **argv, int argc)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(*a);
	while (len_a != 3)
	{
		pb(a, b);
		if (ft_lstsize(*b) > 1 && !check_if_median(*b, argv, argc))
			rotate(b, 'b');
		len_a--;
	}
	len_b = ft_lstsize(*b);
	if (!check_sorted(*a))
		tiny_sort(a);
	while (len_b > 0)
	{
		attribute_targets(a, b);
		attribute_push_cost(a, b);
		find_cheapest(a, b);
		pa(a, b);
		len_b--;
	}
	finish_sort(a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;


	if (argc <= 2)
		return (0);
	if (!(check_all_errors(argv)))
		return (error_print());
	init_stacks(&stack_a, argv);
	if (check_doublon(stack_a))
		return (error_print());
	if (!check_sorted(stack_a))
	{
		if (argc == 3)
			return (sa(&stack_a, 1), 0);
		else if (argc == 4)
			tiny_sort(&stack_a);
		else
			push_swap(&stack_a, &stack_b, argv, argc);
	}
	return (0);
}
