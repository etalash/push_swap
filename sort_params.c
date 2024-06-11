/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:23:42 by stalash           #+#    #+#             */
/*   Updated: 2024/06/11 14:41:43 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_stack(t_stack *a)
{
	if (a == NULL)
		return (1);
	while (a->next != NULL)
	{
		if (a->nbr > a->next->nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	sort_three(t_stack *a)
{
	int	i;
	// t_list_push_swap	*tem;

	i = a->nbr;
	// tem = *a;
	if (a == NULL)
		return ;
	while (a->next != NULL)
	{
		if (a->nbr > a->next->nbr)
		{
			a->nbr = a->next->nbr;
			a->next->nbr = i;
			// a = tem;
		}
		a = a->next;
	}
}
