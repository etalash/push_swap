/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:39:08 by stalash           #+#    #+#             */
/*   Updated: 2024/09/02 13:29:02 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Set the current position of every node
 * in the current state-configuration
*/
void	set_current_position(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (NULL == stack)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

/*
 *	Best match is..
 *   | "The Smallest-bigger value" |
 *
 *  if no node is Bigger, best_match is the Smallest node.
 *  TLDR
 *  With this function every node in b gets its target node in a
*/
// static void	set_target_node(t_stack *a,
// 							t_stack *b)
// {
// 	t_stack	*current_a;
// 	t_stack	*target_node;
// 	long	best_match_index;

// 	while (b)
// 	{
// 		best_match_index = LONG_MAX;
// 		current_a = a;
// 		while (current_a)
// 		{
// 			if (current_a->nbr > b->nbr
// 				&& current_a->nbr < best_match_index)
// 			{
// 				best_match_index = current_a->nbr;
// 				target_node = current_a;
// 			}
// 			current_a = current_a->next;
// 		}
// 		if (LONG_MAX == best_match_index)
// 			b->target_node = find_smallest(a);
// 		else
// 			b->target_node = target_node;
// 		b = b->next;
// 	}
// }

t_stack	*find_max(t_stack *stack) //Define a function that searches a stack and returns the node with the biggest number
{
	long			max; //To store the biggest value so far
	t_stack	*max_node; //To store a pointer that points to the biggest number

	if (!stack)
		return (NULL);
	max = LONG_MIN; //Assign to the biggest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->nbr > max) //Check if the current node value is smaller than the biggest so far
		{
			max = stack->nbr; //If so, update the biggest number so far
			max_node = stack; //Set the pointer to point to the node with the biggest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (max_node);
}


static void	set_target_a(t_stack *a, t_stack *b)//Find `a` node's target in stack `b`
{
	t_stack	*current_b; //To store the pointer to the current node in stack `b` and iterate through each node following
	t_stack	*target_node; //To store the pointer to the target node in stack `b`
	long	best_match_index; //In this case, the best match indexe stores the value of the "closest smaller number" so far

	while (a) //As long as we have nodes in stack `a`
	{
		best_match_index = LONG_MIN; //Assign the smallest `long` as the closest smaller number so far
		current_b = b; //Assign to `current_b` the current `b` node
		while (current_b) //Iteratively search through all the nodes in stack `b` until the end of the stack is reached
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > best_match_index) //Check if `b` node is smaller than `a` node && bigger than the closest smaller number so far
			{
				best_match_index = current_b->nbr; //If so, update the value of the closest smaller number so far
				target_node = current_b; //Assign the current `b` node as the `target_node`
			}
			current_b = current_b->next; //Move to the next `b` node for comparison, until a "closer smaller number" is found
		}
		if (best_match_index == LONG_MIN) //Check if the LONG_MIN hasn't changed, it means we haven't found anything smaller
			a->target_node = find_max(b); //If so, find the biggest `nbr` and set this as the target node
		else
			a->target_node = target_node; //If no "closer smaller number" is found, and the best match has changed
		a = a->next; //Move to the next `a` node to find it's target `b` node
	}
}

/*
 * Set the prices to push the node
 * from b -> a
 * The price checks for the relative positions in the stack
 * for every node, setting the respective price
*/
// void	set_price(t_stack *a, t_stack *b)
// {
// 	int	len_a;
// 	int	len_b;

// 	len_a = stack_len(a);
// 	len_b = stack_len(b);
// 	while (b)
// 	{
// 		b->push_price = b->current_position;
// 		if (!(b->above_median))
// 			b->push_price = len_b - (b->current_position);
// 		if (b->target_node && b->target_node->above_median)
// 			b->push_price += b->target_node->current_position;
// 		else
// 			if (b && b->push_price && b->target_node \
// 				&& b->target_node->current_position)
// 				b->push_price += len_a - (b->target_node->current_position);
// 		b = b->next;
// 	}
// }

// void	set_price(t_stack *a, t_stack *b)
// {
// 	int	len_a;
// 	int	len_b;

// 	len_a = stack_len(a);
// 	len_b = stack_len(b);
// 	while (a)
// 	{
// 		a->push_price = a->current_position;
// 		if (!(a->above_median))
// 			a->push_price = len_a - (a->current_position);
// 		if (a->target_node && a->target_node->above_median)
// 			a->push_price += a->target_node->current_position;
// 		else
// 			a->push_price += len_b - (a->target_node->current_position);
// 		a = a->next;
// 	}
// }

static void	cost_analysis_a(t_stack *a, t_stack *b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	len_a; //To store the length of stack `a`
	int	len_b; //To store the length of stack `b`

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a) //Loop through each node until the end of the stack is reached
	{
		a->push_price = a->current_position; //Assign the current `a` node's push cost, its' index value
		if (!(a->above_median)) //Check if the above_median data is false, meaning it is below median
			a->push_price = len_a - (a->current_position); //If so, update `a` node's push cost to the stack's length - index
		if (a->target_node->above_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
			a->push_price += a->target_node->current_position; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			a->push_price += len_b - (a->target_node->current_position); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
		a = a->next; //Move to the next `a` node for its cost analysis
	}
}

/*
 * Flag the cheapest node in the current
 * stacks configurations
*/
void	set_cheapest(t_stack *b)
{
	long	best_match_value;
	t_stack	*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

/*
 * All the necessary values to make the push
 * 		~Relative Positions
 * 		~Target node, the b node to make emerge
 * 		~Price for every configuration
 * 		~Cheapest in the current configuration
*/
void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
