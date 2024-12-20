/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:23:42 by stalash           #+#    #+#             */
/*   Updated: 2024/06/27 14:53:35 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack **a)
{
	if ((*a)->next->next == NULL)
		sa(a, false);
	else if ((*a)->nbr > (*a)->next->nbr && (*a)->next->nbr < \
		(*a)->next->next->nbr && (*a)->nbr < (*a)->next->next->nbr)
		sa(a, false);
	else if ((*a)->nbr < (*a)->next->nbr && (*a)->next->nbr > \
		(*a)->next->next->nbr && (*a)->nbr < (*a)->next->next->nbr)
	{
		sa(a, false);
		ra(a, false);
	}
	else if ((*a)->nbr < (*a)->next->nbr && (*a)->next->nbr > \
			(*a)->next->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
		rra(a, false);
	else if ((*a)->nbr > (*a)->next->nbr && (*a)->next->nbr < \
			(*a)->next->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
		ra(a, false);
	else if ((*a)->nbr > (*a)->next->nbr && (*a)->next->nbr > \
			(*a)->next->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
	{
		sa(a, false);
		rra(a, false);
	}
}
