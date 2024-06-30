/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:53:08 by stalash           #+#    #+#             */
/*   Updated: 2024/06/30 17:29:27 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	swap(t_stack **h)
// {
// 	t_stack	*first;
// 	t_stack	*second;

// 	first = *h;
// 	second = (*h)->next;
// 	if (h == NULL || *h == NULL || (*h)->next == NULL)
// 		return ;
// 	*h = second;
// 	first->next = second->next;
// 	first->prev = second;
// 	second->prev = NULL;
// 	second->next = first;
// 	if (first->next != NULL)
// 		first->next->prev = first;
// }

// // static void	swap(t_stack **h)
// // {
// // 	int	len;

// // 	len = stack_len(*h);
// // 	if (h == NULL || *h == NULL || len < 1)
// // 		return ;
// // 	*h = (*h)->next;
// // 	(*h)->prev->prev = *h;
// // 	(*h)->prev->next = (*h)->next;
// // 	if ((*h)->next)
// // 		(*h)->next->prev = (*h)->prev;
// // 	(*h)->next = (*h)->prev;
// // 	(*h)->prev = NULL;
// // }

// void	sa(t_stack **a, bool check)
// {
// 	swap(a);
// 	if (!check)
// 		write(1, "sa\n", 3);
// }

// void	sb(t_stack **b, bool check)
// {
// 	swap(b);
// 	if (!check)
// 		write(1, "sb\n", 3);
// }

// void	ss(t_stack **a, t_stack **b, bool check)
// {
// 	swap(a);
// 	swap(b);
// 	if (!check)
// 		write(1, "ss\n", 3);
// }

static void	swap(t_stack **head)
{
	int	len;

	len = stack_len(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack	**a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
