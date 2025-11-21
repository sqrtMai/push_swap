#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include "libft/libft.h"

#include <stdbool.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct l_list
{
	int nbr;
	int index;
	int push_cost;
	bool above_median;
	bool cheapest;
	struct l_list *target_node;
	struct l_list *next;
	struct l_list *previous;
}	f_list;


// Manipulation de listes
void	ft_lstadd_front(f_list **lst, f_list *new);
void	ft_lstadd_back_ps(f_list **lst, f_list *new);
f_list	*ft_lstnew_ps(int content);
f_list	*ft_lstlast(f_list *lst);
int		ft_lstsize(f_list *lst);

// Gestion d'erreurs
int check_all_errors(char **argv);
int error_print(void);
int	is_valid(char **argv);
int check_sorted(f_list *head);
int check_doublon(f_list *a);
int hay_overflow(char **argv);

//UTILS
f_list		*find_min(f_list *stack);
f_list		*find_max(f_list *stack); //Fonctions qui permettent de trouver le min ou le max d'un stack précise
int			is_max(f_list *a, f_list *b); // Celle-ci compare un node actuel avec tous les autres d'une autre stack
void		current_index(f_list *stack);
long long	ft_atol(char *str);
void		init_stacks(f_list **a, char **argv);

//		SWAP ACTIONS
//PUSH
void pa(f_list **a, f_list **b);
void pb(f_list **a, f_list **b);

//SWAP
void sa(f_list **head, int i);
void sb(f_list **head, int i);
void ss(f_list **a, f_list **b);

//ROTATE
void rotate(f_list **head, char c);
void rr(f_list **a, f_list **b);

//REVERSE ROTATE
void reverse_rotate(f_list **head, char c);
void rrr(f_list **a, f_list **b);

void push_swap (f_list **a, f_list **b);

#endif
