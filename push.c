/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:09:46 by stalash           #+#    #+#             */
/*   Updated: 2024/06/30 17:34:06 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	push(t_stack **a, t_stack **b)
// {
// 	t_stack	*temp;

// 	if (a == NULL || *a == NULL)
// 		return ;
// 	temp = *a;
// 	*a = (*a)->next;
// 	if (*a != NULL)
// 		(*a)->prev = NULL;
// 	temp->next = *b;
// 	if (*b != NULL)
// 		(*b)->prev = temp;
// 	temp->prev = NULL;
// 	*b = temp;
// }

// void	pa(t_stack **a, t_stack **b, bool check)
// {
// 	push(a, b);
// 	if (!check)
// 		write(1, "pa\n", 3);
// }

// void	pb(t_stack **a, t_stack **b, bool check)
// {
// 	push(b, a);
// 	if (!check)
// 		write(1, "pb\n", 3);
// }

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_push;

	if (NULL == *src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stack **a, t_stack **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
