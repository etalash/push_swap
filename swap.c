/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:53:08 by stalash           #+#    #+#             */
/*   Updated: 2024/06/21 16:08:11 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **h)
{
	t_stack	*first;
	t_stack	*second;

	first = *h;
	second = (*h)->next;
	if (h == NULL || *h == NULL || (*h)->next == NULL)
		return ;
	*h = second;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	if (first->next != NULL)
		first->next->prev = first;
}

void	sa(t_stack **a, bool check)
{
	swap(a);
	if (!check)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool check)
{
	swap(b);
	if (!check)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool check)
{
	swap(a);
	swap(b);
	if (!check)
		write(1, "ss\n", 3);
}
