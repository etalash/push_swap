/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:09:46 by stalash           #+#    #+#             */
/*   Updated: 2024/06/12 19:56:16 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (a == NULL || *a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a != NULL)
		(*a)->prev = NULL;
	temp->next = *b;
	if (*b != NULL)
		(*b)->prev = temp;
	temp->prev = NULL;
	*b = temp;
}

void	pa(t_stack **a, t_stack **b, bool check)
{
	push(a, b);
	if (!check)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, bool check)
{
	push(b, a);
	if (!check)
		write(1, "pb\n", 3);
}
