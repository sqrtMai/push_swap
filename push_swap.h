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
	struct l_list *next;
	struct l_list *previous;
}	f_list;


f_list	*ft_lstnew_ps(int content, int *temp_sorted, int size);
void	ft_lstadd_back_ps(f_list ***lst, f_list *new);
int error_print(void);
int str_len(char **argv);
int *bubble_sort(char **argv);
int	is_valid(char **argv);
int check_doublon(char **argv);
int hay_overflow(char **argv);
int check_all_errors(char **argv);
long long ft_atol(char *str);
int find_index(int content, int *temp_sorted, int size);
//void push_swap(int *stack);


#endif
