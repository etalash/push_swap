/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subordinate_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:28:04 by stalash           #+#    #+#             */
/*   Updated: 2024/09/02 12:33:36 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *s)
{
	int		x;
	int		sign;
	long	out;

	x = 0;
	sign = 1;
	out = 0;
	while (s[x] && (s[x] == ' ' || (s[x] >= 9 && s[x] <= 13)))
		x++;
	if (s[x] == '-')
	{
		sign = -1 * sign;
		x++;
	}
	else if (s[x] == '+')
		x++;
	while (s[x] && (s[x] >= '0' && s[x] <= '9'))
	{
		out = out * 10 + s[x] - '0';
		x++;
	}
	return (out * sign);
}

// t_stack	*get_cheapest(t_stack *stack) //Define a function that searches for the cheapest node, that is set by bool
// {
// 	if (!stack)
// 		return (NULL);
// 	while (stack)
// 	{
// 		if (stack->cheapest)
// 			return (stack);
// 		stack = stack->next;
// 	}
// 	return (NULL);
// }



t_stack	*find_min(t_stack *stack) //Define a function that searches a stack and returns the node with the smallest number
{
	long	min; //To store the smallest value so far
	t_stack	*min_node; //To store a pointer that points to the smallest number

	if (!stack)
		return (NULL);
	min = LONG_MAX; //Assign to the smallest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->nbr < min) //Check if the current node value is smaller than the smallest so far
		{
			min = stack->nbr; //If so, update the smallest number so far
			min_node = stack; //Set the pointer to point to the node with the smallest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (min_node);
}

// static void	min_on_top(t_stack **a) //Define a function that moves the smallest number to the top
// {
// 	while ((*a)->nbr != find_min(*a)->nbr) //As long as the smallest number is not at the top
// 	{
// 		if (find_min(*a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
// 			ra(a, false);
// 		else
// 			rra(a, false);
// 	}
// }
