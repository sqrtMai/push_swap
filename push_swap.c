#include "include/push_swap.h"

void tiny_sort(f_list **a, char **argv)
{
	write(1, "tu rentres dans le sort\n", 25);
	if ((*a)->nbr > (*a)->next->nbr) // if not sorted: if a > b : sa
		sa(a, 1);
	if (!check_sorted(*a, argv))
		reverse_rotate(a, 'a');
	if (!check_sorted(*a, argv))
		sa(a, 1);
}

f_list *smallest_bigger(f_list **a, f_list *b)
{
	long difference;
	f_list *temp = *a;
	f_list *smallest_bigger;

	smallest_bigger = *a;
	difference = temp->nbr - b->nbr;
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

void attribute_targets(f_list **a, f_list **b)
{
	f_list *b_head;
	f_list *a_head;

	b_head = *b;
	a_head = *a;
	while (*b)
	{
		if (is_max(a, *b))
			(*b)->target_node = find_min(a);
		else
			(*b)->target_node = smallest_bigger(a, *b);
		*b = (*b)->next;
		/* en gros tu prends le nombre actuel de b
		et tu le compares avec CHAQUE nombre de A
		et tu l'attribues à celui qui à la plus petit difference*/
	}
	*b = b_head;
}

/*en gros si c'est dans les deux premiers tu swap, et tout le reste tu dois r ou rr * le push cost
rr si c'est en dessous de la mediane, r si au dessus*/

/*faut faire gaffe aussi à si les deux sont possibles en un seul move au lieu de faire les des séprament*/
/*if push cost = 1 pour les deux && au dessus mediane pour les deux
	ss
	*/
/*if push cost = 1 pour les deux && en dessous mediane pour les deux
	rrr
	*/

// if ((((*cheapest)->push_cost == 1) && ((*cheapest)->target_node->push_cost == 1))
// 	&& (((*cheapest)->above_median) && ((*cheapest)->target_node->above_median)))
// 	return (ss(&(*cheapest)->previous, &(*cheapest)->target_node->previous));

// if ((((*cheapest)->push_cost == 1) && ((*cheapest)->target_node->push_cost == 1))
// 	&& (((*cheapest)->above_median = false) && ((*cheapest)->target_node->above_median = false)))
// 	return(rrr(&(*cheapest)->previous, &(*cheapest)->target_node->previous));

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
	if ((((*cheapest)->push_cost == 1) && ((*cheapest)->target_node->push_cost == 1))
		&& (((*cheapest)->above_median) && ((*cheapest)->target_node->above_median)))
		return (ss(a, b));
	else if ((((*cheapest)->push_cost == 1) && ((*cheapest)->target_node->push_cost == 1))
		&& (((*cheapest)->above_median == false) && ((*cheapest)->target_node->above_median == false)))
		return(rrr(a, b));
	if (((*cheapest)->push_cost == 1) && (((*cheapest)->above_median)))
		sb(b, 1);
	if (((*cheapest)->push_cost == 1) && (((*cheapest)->above_median == false)))
		reverse_rotate(b, 'b');
	if (((*cheapest)->target_node->push_cost == 1) && (((*cheapest)->target_node->above_median)))
		sa(a, 1);
	if (((*cheapest)->target_node->push_cost == 1) && ((!(*cheapest)->target_node->above_median == false)))
		reverse_rotate(a, 'a');
	if ((*cheapest)->push_cost > 1)
		superior_to_one(cheapest, a, (*cheapest)->push_cost, 'b');

	if ((*cheapest)->target_node->push_cost > 1)
		superior_to_one(&(*cheapest)->target_node, a, (*cheapest)->target_node->push_cost, 'a');

}
void find_cheapest(f_list **a, f_list **b)
{
	f_list *actual_cheapest;
	f_list *temp;
	int price;

	temp = *b;
	actual_cheapest = temp;
	price = temp->push_cost + temp->target_node->push_cost;
	//write(1, "passe", 5);
	while (temp)
	{
		if ((temp->push_cost + temp->target_node->push_cost) < price)
		{
			price = temp->push_cost + temp->target_node->push_cost;
			actual_cheapest = temp;
			if (price == 0)
			{
				actual_cheapest->cheapest = true;
				return;
			}
		}
		temp = temp->next;
	}
	actual_cheapest->cheapest = true;

	bring_cheapest_at_top(&actual_cheapest, a, b);
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
		if (temp->above_median == false)
			temp->push_cost = len_b - temp->index;
		else
			temp->push_cost = temp->index;
		if (temp->target_node->above_median == false)
			temp->target_node->push_cost = len_a - temp->target_node->index;
		else
			temp->target_node->push_cost = temp->target_node->index;
		write(1, "ok?\n", 4);

		temp = temp->next;
	}
}

void push_swap(f_list **a, f_list **b, char **argv)
{
	int len_a;
	f_list *temp;

	temp = *b;
	len_a = ft_lstsize(*a);
	while (len_a != 3)
	{
		pb(a, b);
		len_a--;
	}
	if (!check_sorted(*a, argv))
		tiny_sort(a, argv);
	write(1, "tiny sort passed\n", 17);
	attribute_targets(a, b);
	write(1, "attribute target passed\n", 24);
	attribute_push_cost(a, b);
	write(1, "attribute cost-- passed\n", 24);
	find_cheapest(a, b);
	pa(a, b);
	write(1, "gg", 2);

	attribute_targets(a, b);
	attribute_push_cost(a, b);
	find_cheapest(a, b);
	pa(a, b);

	//	bring_cheapest_at_top(a, b);
	// NEXT STEP
	// FAire en sorte que les nodes B aient une target node d'une node en A
	// (C'est à dire le closest bigger)
	// DONE		// Si le node en B est plus grand que n'importe quoi dans la stack A
	//  tu lui attribues le plus petit dans la stack A
	//  attribute_targets(f_list **a, f_list **b);

	// NEXT STEP
	// Trouver le cheapest node à déplacer
	// Mais avant ça je dois attribuer un push price
	// (somme de b->current position + TN->current_pos)
	// Si avant médiane : le price est juste la position
	// si après : len - position
	// if (median== true)
	//		price_b = len - position
	// et en gros tu dois trouver la combinaison
	// a cost + b cost la cheapest
	// (si c'est 0 tu push instant)
	// maitenant que t'as trouvé le cheapest
	// tu ramènes les deux tout en haut de leur stack
	// selon leur position tu dois savoir quel move faire
	// puis une fois que c'est tout en haut
	// tu PA(b);
	// et tu refresh tout
}

int main(int argc, char **argv)
{
	f_list *head_a;
	f_list *head_b;
	f_list **stack_a = &head_a;
	f_list **stack_b = &head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		return (1);
	if (!(check_all_errors(argv)))
		return error_print();
	init_stacks(&head_a, argv);

	if (!check_sorted(head_a, argv))
	{
		if (str_len(argv) == 2)
			sa(&head_a, 1);
		else if (str_len(argv) == 3)
			tiny_sort(stack_a, argv);
		else
			push_swap(stack_a, stack_b, argv);
	}
	printf("\n%d - ", head_a->nbr);
	printf("%d - ", head_a->next->nbr);
	printf("%d - ", head_a->next->next->nbr);
	printf("%d - ", head_a->next->next->next->nbr);
	printf("%d", head_a->next->next->next->next->nbr);

	return 0;
}
