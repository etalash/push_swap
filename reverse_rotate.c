/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:29:20 by stalash           #+#    #+#             */
/*   Updated: 2024/06/30 17:40:05 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	revers_rotate(t_stack **h)
// {
// 	t_stack	*last_node;

// 	last_node = *h;
// 	if (h == NULL || *h == NULL || (*h)->next == NULL)
// 		return ;
// 	while (last_node->next != NULL)
// 		last_node = last_node->next;
// 	if (last_node->prev != NULL)
// 		last_node->prev->next = NULL;
// 	last_node->next = *h;
// 	(*h)->prev = last_node;
// 	last_node->prev = NULL;
// 	*h = last_node;
// }

// // static void	revers_rotate(t_stack **h)
// // {
// // 	int		len;
// // 	t_stack	*last_node;

// // 	len = stack_len(*h);
// // 	last_node = *h;
// // 	if (h == NULL || *h == NULL || len < 1)
// // 		return ;
// // 	while (last_node->next)
// // 		last_node = last_node->next;
// // 	(*h)->prev = last_node;
// // 	(*h)->prev->next = *h;
// // 	(*h)->prev->prev = NULL;
// // 	last_node->prev->next = NULL;
// // }

// void	rra(t_stack **a, bool check)
// {
// 	revers_rotate(a);
// 	if (!check)
// 		write(1, "rra\n", 4);
// }

// void	rrb(t_stack **b, bool check)
// {
// 	revers_rotate(b);
// 	if (!check)
// 		write(1, "rrb\n", 4);
// }

// void	rrr(t_stack **a, t_stack **b, bool check)
// {
// 	revers_rotate(a);
// 	revers_rotate(b);
// 	if (!check)
// 		write(1, "rrr\n", 4);
// }

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int		len;

	len = stack_len(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	last = ft_lst_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
