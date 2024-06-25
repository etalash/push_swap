/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:47:02 by stalash           #+#    #+#             */
/*   Updated: 2024/06/25 18:28:44 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	stack_len(t_stack *stack)
// {
// 	int	i;

// 	i = 0;
// 	while (stack)
// 	{
// 		i++;
// 		stack = stack->next;
// 	}
// 	return (i);
// }

/*
 * Find the smallest value node
*/
// t_stack	*find_smallest(t_stack *stack)
// {
// 	long			smallest;
// 	t_stack			*smallest_node;

// 	if (NULL == stack)
// 		return (NULL);
// 	smallest = LONG_MAX;
// 	while (stack)
// 	{
// 		if (stack->nbr < smallest)
// 		{
// 			smallest = stack->nbr;
// 			smallest_node = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	return (smallest_node);
// }

/*
 * Find the smallest value node
*/
t_stack	*find_smallest(t_stack *stack)
{
	long			smallest;
	t_stack	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < smallest)
		{
			smallest = stack->nbr;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

/*
 * Return the cheapest node
 * that is already flagged
*/
t_stack	*return_cheapest(t_stack *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
