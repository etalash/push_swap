/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:33:47 by stalash           #+#    #+#             */
/*   Updated: 2024/09/02 12:00:20 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// dont need this one

// static t_stack	*find_highest(t_stack *stack)
// {
// 	int		highest;
// 	t_stack	*highest_node;

// 	if (NULL == stack)
// 		return (NULL);
// 	highest = INT_MIN;
// 	while (stack)
// 	{
// 		if (stack->nbr > highest)
// 		{
// 			highest = stack->nbr;
// 			highest_node = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	return (highest_node);
// }

/*
 * When i have 3 nodes, easy to sort
 * 	~If the 1* is the biggest, ra (biggestto bottom)
 * 	~If the 2* is the biggest, rra (biggest to bottom)
 * 	~Now i have forcefully the Biggest at the bottom
 * 		so i just chek 1° and 2°
*/
// void	tiny_sort(t_stack **a)
// {
// 	t_stack	*highest_node;

// 	highest_node = find_highest(*a);
// 	if (*a == highest_node)
// 		ra(a, false);
// 	else if ((*a)->next == highest_node)
// 		rra(a, false);
// 	if ((*a)->nbr > (*a)->next->nbr)
// 		sa(a, false);
// }

/*
 * Handle input 5
*/
void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}

static void	set_target_b(t_stack *a, t_stack *b) //Define a function that sets for the current `a` node, its target node from stack `a`
{
	t_stack	*current_a; //To store the pointer to the current `a` node
	t_stack	*target_node; //To store the pointer of the target node for `b` node
	long	best_match_index; //To store the "closest bigger" number so far

	while (b)
	{
		best_match_index = LONG_MAX; //Set the current best match to the max long
		current_a = a; //Assign the pointer to point to the current `a` node
		while (current_a) //While the pointer is not set to NULL
		{
			if (current_a->nbr > b->nbr
				&& current_a->nbr < best_match_index) //Check if the `a` node's value is bigger than `b` node, && smaller than the "closest bigger" so far
			{
				best_match_index = current_a->nbr; //Set the best match as the value in the current `a` node
				target_node = current_a; //Set `b` node's target node pointer to point to the current `a` node
			}
			current_a = current_a->next; //Move to the next `a` node for processing
		}
		if (best_match_index == LONG_MAX) //If the best match value has not changed
			b->target_node = find_min(a); //Set `b` node's target node pointer to point to the smallest number in stack `a`
		else
			b->target_node = target_node; //If the best match value has been updated, then we have a target node for the current `b` node
		b = b->next; //Move to the next `b` node for processing
	}
}

void	init_nodes_b(t_stack *a, t_stack *b) //Define a function that prepares the nodes for pushing `b` to `a`
{
	set_current_position(a);
	set_current_position(b);
	set_target_b(a, b);
}
