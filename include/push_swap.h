#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct l_list
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct l_list	*target_node;
	struct l_list	*next;
	struct l_list	*previous;
}			t_list;

// Manipulation de listes
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back_ps(t_list **lst, t_list *new);
t_list		*ft_lstnew_ps(int content);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);

// Gestion d'erreurs
int			check_all_errors(char **argv);
int			is_valid(char **argv);
int			check_sorted(t_list *head);
int			check_doublon(t_list *a);
int			hay_overflow(char **argv);

// UTILS
t_list		*find_min(t_list *stack);
t_list		*find_max(t_list *stack);
int			is_max(t_list *a, t_list *b);
void		current_index(t_list *stack);
long long	ft_atol(char *str);
void		init_stacks(t_list **a, char **argv);
int			check_if_median(t_list *b, char **argv, int argc);

// UTILS POUR L'ALGO
void		bring_cheapest_at_top(t_list **cheapest, t_list **a, t_list **b);
void		find_cheapest(t_list **a, t_list **b);
t_list		*smallest_bigger(t_list *a, t_list *b);
void		attribute_push_cost(t_list **a, t_list **b);
void		attribute_targets(t_list **a, t_list **b);

//		SWAP ACTIONS
// PUSH
void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);

// SWAP
void		sa(t_list **head, int i);
void		sb(t_list **head, int i);
void		ss(t_list **a, t_list **b);

// ROTATE
void		rotate(t_list **head, char c);
void		rr(t_list **a, t_list **b);

// REVERSE ROTATE
void		reverse_rotate(t_list **head, char c);
void		rrr(t_list **a, t_list **b);

// void push_swap (t_list **a, t_list **b);

#endif
