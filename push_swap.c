#include "include/push_swap.h"

void tiny_sort(f_list **a, char **argv)
{
	write(1, "tu rentres dans le sort\n", 25);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
	if (!check_sorted(*a, argv))
		reverse_rotate(a, 'a');
	if (!check_sorted(*a, argv))
		sa(a, 1);
}

void superior_to_one(f_list **cheapest, f_list **head, int push_cost, char stack)
{
	if ((*cheapest)->above_median == true)
	{
		while (*head != *cheapest)
			rotate(head, stack);
	}
	if ((*cheapest)->above_median == false)
	{
		while (*head != *cheapest)
			reverse_rotate(head, stack);
	}
}

void bring_cheapest_at_top(f_list **cheapest, f_list **a, f_list **b)
{

	//TODO A OPTIMISER
	if ((*cheapest)->push_cost == 2 && (*a != (*cheapest)->target_node && *b != (*cheapest) && ((*cheapest)->target_node->above_median == true && (*cheapest)->above_median == true)))
		rrr(a, b);
	else if ((*cheapest)->push_cost == 2 && (*a != (*cheapest)->target_node && *b != (*cheapest) && ((*cheapest)->target_node->above_median == false && (*cheapest)->above_median == false)))
		rr(a, b);
	if ((*cheapest)->target_node == (*a)->next)
		rotate(a, 1);
	if ((*cheapest) == (*b)->next)
		rotate(b, 1);
	while (*a != (*cheapest)->target_node || *b != (*cheapest))
	{
		if ((*cheapest)->target_node->above_median == false && *a != (*cheapest)->target_node)
			reverse_rotate(a, 'a');
		if ((*cheapest)->target_node->above_median == true && *a != (*cheapest)->target_node)
			rotate(a, 'a');
		if ((*cheapest)->above_median == false && *b != (*cheapest))
			reverse_rotate(b, 'b');
		if ((*cheapest)->above_median == true && *b != (*cheapest))
			rotate(b, 'b');
	}
}
void find_cheapest(f_list **a, f_list **b)
{
	f_list *actual_cheapest;
	f_list *temp;
	int price;

	temp = *b;
	actual_cheapest = temp;
	price = temp->push_cost;
	while (temp)
	{
		if ((temp->push_cost) < price)
		{
			price = temp->push_cost;
			actual_cheapest = temp;
			if (price == 0)
			{
				actual_cheapest->cheapest = true;
				bring_cheapest_at_top(&actual_cheapest, a, b);
				return;
			}
		}
		temp = temp->next;
	}
	actual_cheapest->cheapest = true;
	bring_cheapest_at_top(&actual_cheapest, a, b);
}

f_list *closest_smaller(f_list *a, f_list *b)
{
	long difference;
	f_list *temp = b;
	f_list *closest_smaller;

	closest_smaller = b;
	difference = INT_MIN;

	while (temp)
	{
		if ((temp->nbr - a->nbr < 0) && (temp->nbr - a->nbr > difference)) // TODO FAIRE GAFFE A L'OVERFLOW LORSQUE TU SOUSTRAITS DEUX TRES PETITS NOMBRES
		{
			difference = a->nbr - temp->nbr;
			closest_smaller = temp;
		}
		temp = temp->next;
	}
	return closest_smaller;
}

f_list *smallest_bigger(f_list *a, f_list *b)
{
	long difference;
	f_list *temp = a;
	f_list *smallest_bigger;

	smallest_bigger = a;
	difference = INT_MAX;

	while (temp)
	{
		/* en gros tu soustrais a avec b, déjà faut que le nombre soit positif (sinon ça voudrait dire qu'il est plus petit)
		une fois que t'as trouvé un nombre plus grand, tu l'attribues dans difference puis à chaque fois t'essayes
		de trouver un nombre qui a une plus petit difference*/

		if ((temp->nbr - b->nbr > 0) && (temp->nbr - b->nbr < difference)) // TODO FAIRE GAFFE A L'OVERFLOW LORSQUE TU SOUSTRAITS DEUX TRES PETITS NOMBRES
		{
			difference = temp->nbr - b->nbr;
			smallest_bigger = temp;
		}
		temp = temp->next;
	}
	return smallest_bigger;
}

void attribute_push_cost(f_list **a, f_list **b)
{
	int len_b;
	int len_a;
	f_list *temp;
	// Mais avant ça je dois attribuer un push price
	// (somme de b->current position + TN->current_pos)
	// Si avant médiane : le price est juste la position
	// si après : len - position
	// if (median== true)
	//		price_b = len - position

	// Above median true si le chiffre est AU DESSUS dans la stack
	len_a = ft_lstsize(*a);
	len_b = ft_lstsize(*b);
	temp = *b;
	while (temp)
	{
		temp->push_cost = temp->index;
		if (temp->above_median == false)
			temp->push_cost = temp->index - len_b;
		if (temp->target_node->above_median == false)
			temp->push_cost += temp->target_node->index;
		else
			temp->push_cost += len_a - temp->target_node->index;
		temp = temp->next;
	}
}

void attribute_targets(f_list **a, f_list **b)
{
	f_list *b_head;
	f_list *a_head;

	b_head = *b;
	a_head = *a;
	while (*b)
	{
		if (is_max(a_head, *b))
		{
			(*b)->target_node = find_min(a_head);
		}
		else
		{
			(*b)->target_node = smallest_bigger(a_head, *b);
			// printf("target node de %d : %d\n", (*b)->nbr, (*b)->target_node->nbr);
		}

		*b = (*b)->next;
		/* en gros tu prends le nombre actuel de b
		et tu le compares avec CHAQUE nombre de A
		et tu l'attribues à celui qui à la plus petit difference*/
	}
	*b = b_head;
}

void finish_sort(f_list **stack)
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

void push_swap(f_list **a, f_list **b, char **argv)
{
	int len_a;
	f_list *temp;

	temp = *a;
	len_a = ft_lstsize(*a);
	while (len_a != 3)
	{
		pb(a, b);
		len_a--;
	}
	int len_b = ft_lstsize(*b);
	if (!check_sorted(*a, argv))
		tiny_sort(a, argv);

	/*push 2 fois de a à B, attribuer un biggest smaller, push cost, puis bouger
	le cheapest de A à B et ce jusqu'à ce qu'il reste plus que 3 nodes dans a
	et dès qu'il reste que 3 nodes dans a tu sort three et tu fais l'inverse*/
	while (len_b > 0)
	{
		// if (len_b == 2)
		// 	sb(b, 1);
		attribute_targets(a, b);
		attribute_push_cost(a, b);
		find_cheapest(a, b);
		pa(a, b);
		printf("\n");
		len_b--;
	}
	finish_sort(a);
	temp = *a;
	// printf("%d est-il above mediane : %d\n", temp->next->next->nbr, temp->next->next->above_median);
	while (temp)
	{
		printf("%d - ", temp->nbr);
		temp = temp->next;
	}
}
int main(int argc, char **argv)
{
	f_list *head_a;
	f_list *head_b;
	head_a = NULL;
	head_b = NULL;
	f_list **stack_a = &head_a;
	f_list **stack_b = &head_b;

	if (argc == 2)
		return (1);

	if (!(check_all_errors(argv)))
		return error_print();

	init_stacks(&head_a, argc, argv);

	if (check_doublon(head_a))
		return error_print();

	if (!check_sorted(head_a, argv))
	{
		if (argc == 3)
			return (sa(&head_a, 1), 0);
		else if (argc == 4)
			tiny_sort(stack_a, argv);
		else
			push_swap(stack_a, stack_b, argv);
	}
	return 0;
}
