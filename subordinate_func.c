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

t_stack	*find_min(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
