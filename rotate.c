/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:11:36 by stalash           #+#    #+#             */
/*   Updated: 2024/06/30 17:39:22 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	rotate(t_stack **h)
// {
// 	t_stack	*first_node;
// 	t_stack	*last_node;

// 	first_node = *h;
// 	last_node = *h;
// 	if (h == NULL || *h == NULL || (*h)->next == NULL)
// 		return ;
// 	while (last_node->next != NULL)
// 		last_node = last_node->next;
// 	*h = first_node->next;
// 	(*h)->prev = NULL;
// 	last_node->next = first_node;
// 	first_node->prev = last_node;
// 	first_node->next = NULL;
// }

// // static void	rotate(t_stack **h)
// // {
// // 	int		len;
// // 	t_stack	*last_node;

// // 	len = stack_len(*h);
// // 	last_node = *h;
// // 	if (h == NULL || *h == NULL || len < 1)
// // 		return ;
// // 	while (last_node->next)
// // 		last_node = last_node->next;
// // 	last_node->next = *h;
// // 	(*h) = (*h)->next;
// // 	(*h)->prev = NULL;
// // 	last_node->next->prev = last_node;
// // 	last_node->next->next = NULL;
// // }

// void	ra(t_stack **a, bool check)
// {
// 	rotate(a);
// 	if (!check)
// 		write(1, "ra\n", 3);
// }

// void	rb(t_stack **b, bool check)
// {
// 	rotate(b);
// 	if (!check)
// 		write(1, "rb\n", 3);
// }

// void	rr(t_stack **a, t_stack **b, bool check)
// {
// 	rotate(a);
// 	rotate(b);
// 	if (!check)
// 		write(1, "rr\n", 3);
// }

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	int				len;

	len = stack_len(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = ft_lst_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}
