/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:31:02 by stalash           #+#    #+#             */
/*   Updated: 2024/09/02 12:59:39 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

// errors and some other subordnet function

bool	syntax_error(const char *str);
long	ft_atol(const char *s);
char	**s_split(char const *s, char c);
void	deallocation(t_stack **a);
void	dealloc(t_stack **a, char **argv, bool argc);
int		repeated_num(t_stack *stack, int num);

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

// functions for process of the Alguritum

bool	stack_sorted(t_stack *stack);
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
void	push_swap(t_stack **a, t_stack **b);
void	set_current_position(t_stack *stack);
void	set_cheapest(t_stack *b);
void	init_nodes(t_stack *a, t_stack *b);
t_stack	*find_smallest(t_stack *stack);
t_stack	*return_cheapest(t_stack *stack);
int		stack_len(t_stack *stack);
void	simple_sort(t_stack **a);
void	init_nodes_b(t_stack *a, t_stack *b);
t_stack	*find_min(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	reverse_rotate_both(t_stack **a, t_stack **b, \
								t_stack *cheapest_node);
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
t_stack	*find_max(t_stack *stack);

#endif
