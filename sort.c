/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:06:43 by stalash           #+#    #+#             */
/*   Updated: 2024/09/02 13:28:05 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Loop decays once
 * 		~cheapest_node tops is a
 * 		~relative target_node tops in b
*/
static void	rotate_both(t_stack **a,
						t_stack **b,
						t_stack*cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack **a,
								t_stack **b,
								t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

/*
 * Conclude the rotation of the stacks
*/
void	finish_rotation(t_stack **stack,
							t_stack *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

/*
 * Move the node from 'b' to 'a'
 * with the metadata available in the node
 * 1)Make the target nodes emerge
 * 2)push in A
*/
// static void	move_nodes(t_stack **a, t_stack **b)
// {
// 	t_stack	*cheapest_node;

// 	cheapest_node = return_cheapest(*b);
// 	if (cheapest_node->above_median && cheapest_node->target_node
// 		&& cheapest_node->target_node->above_median)
// 		rotate_both(a, b, cheapest_node);
// 	else if (!(cheapest_node->above_median)
// 		&& !(cheapest_node->target_node->above_median))
// 		reverse_rotate_both(a, b, cheapest_node);
// 	finish_rotation(b, cheapest_node, 'b');
// 	finish_rotation(a, cheapest_node->target_node, 'a');
// 	pa(a, b, false);
// }

// void	push_swap(t_stack **a, t_stack **b)
// {
// 	t_stack	*smallest;
// 	int		len_a;

// 	len_a = stack_len(*a);
// 	if (len_a == 5)
// 		sort_five(a, b);
// 	else
// 	{
// 		while (len_a-- > 3)
// 			pb(b, a, false);
// 	}
// 	simple_sort(a);
// 	while (*b)
// 	{
// 		init_nodes(*a, *b);
// 		move_nodes(a, b);
// 	}
// 	set_current_position(*a);
// 	smallest = find_smallest(*a);
// 	if (smallest->above_median)
// 		while (*a != smallest)
// 			ra(a, false);
// 	else
// 		while (*a != smallest)
// 			rra(a, false);

t_stack	*get_cheapest(t_stack *stack) //Define a function that searches for the cheapest node, that is set by bool
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
// }

void	prep_for_push(t_stack **stack,
						t_stack *top_node,
						char stack_name) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

// static void	rev_rotate_both(t_stack **a,
// 								t_stack **b,
// 								t_stack *cheapest_node) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
// {
// 	while (*b != cheapest_node->target_node
// 		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
// 		rrr(a, b, false); //Reverse rotate both `a` and `b` nodes
// 	set_current_position(*a); //Refresh current node positions
// 	set_current_position(*b);
// }

static void	move_a_to_b(t_stack **a, t_stack **b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_stack	*cheapest_node; //To store the pointer to the cheapest `a` node

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median) //If both the cheapest `a` node and its target `b` node are above the median
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median)) //If both the cheapest `a` node and its target `b` node are below the median
		reverse_rotate_both(a, b, cheapest_node); //`rev_rotate_both` will execute if neither nodes are at the top
	prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(b, cheapest_node->target_node, 'b'); //Ensure the target node is at the top, ready for pushing
	pb(b, a, false);
}

static void	move_b_to_a(t_stack **a, t_stack **b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a`
{
	prep_for_push(a, (*b)->target_node, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	pa(a, b, false);
}

static void	min_on_top(t_stack **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->nbr != find_min(*a)->nbr) //As long as the smallest number is not at the top
	{
		if (find_min(*a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
			ra(a, false);
		else
			rra(a, false);
	}
}

void	push_swap(t_stack **a, t_stack **b) //Define a function that sorts stack `a` if it has more than 3 nodes
{
	int	len_a; //To store the length of stack `a`

	len_a = stack_len(*a);
	// if (len_a-- > 3 && !stack_sorted(*a)) //If stack `a` has more than three nodes and aren't sorted
	// 	pb(b, a, false);
	// if (len_a-- > 3 && !stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
	// 	pb(b, a, false);
	if (len_a <= 5)
		simple_sort(a);
	else
	{
		while (len_a-- > 3 && !stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
		{
			init_nodes(*a, *b); //Iniate all nodes from both stacks
			move_a_to_b(a, b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
		}
		// simple_sort(a);
		while (*b) //Until the end of stack `b` is reached
		{
			init_nodes_b(*a, *b); //Initiate all nodes from both stacks
			move_b_to_a(a, b); //Move all `b` nodes back to a sorted stack `a`
		}
		set_current_position(*a); //Refresh the current position of stack `a`
		min_on_top(a); //Ensure smallest number is on top
	}
}
