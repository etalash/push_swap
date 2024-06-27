/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:31:02 by stalash           #+#    #+#             */
/*   Updated: 2024/06/27 15:08:51 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include <unistd.h>
// # include <stdlib.h>
// # include <limits.h>
// # include "../libft/libft.h"
// # include <stdio.h>
// # include <stdbool.h>

// typedef struct s_list_push_swap
// {
// 	int						nbr;
// 	struct s_list_push_swap	*prev;
// 	struct s_list_push_swap	*next;
// }				t_stack;

# include <stdlib.h>
# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack;

// errors, and some other subordinate functions

// int		syntax_error(char *argv);

bool	syntax_error(const char *str);
long	ft_atol(const char *s);
char	**s_split(char const *s, char c);
void	deallocation(t_stack **a);
void	dealloc(t_stack **a, char **argv, bool argc);
int		repeated_num(t_stack *stack, int num);
// int		stack_len(t_stack *stack);

// swap, rotate, revers_rotate, push

void	sa(t_stack **a, bool check);
void	sb(t_stack **b, bool check);
void	ss(t_stack **a, t_stack **b, bool check);
void	ra(t_stack **a, bool check);
void	rb(t_stack **b, bool check);
void	rr(t_stack **a, t_stack **b, bool check);
void	rra(t_stack **a, bool check);
void	rrb(t_stack **b, bool check);
void	rrr(t_stack **a, t_stack **b, bool check);
void	pa(t_stack **a, t_stack **b, bool check);
void	pb(t_stack **a, t_stack **b, bool check);

// sorting params

// int		sorted_stack(t_stack *a);
// void	sort_three(t_stack **a);

// soring
bool	stack_sorted(t_stack *stack);
// void	tiny_sort(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
void	push_swap(t_stack **a, t_stack **b);
void	set_current_position(t_stack *stack);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	init_nodes(t_stack *a, t_stack *b);
t_stack	*find_smallest(t_stack *stack);
t_stack	*return_cheapest(t_stack *stack);
int		stack_len(t_stack *stack);
void	simple_sort(t_stack **a);

#endif
