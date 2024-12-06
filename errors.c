/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:25:49 by stalash           #+#    #+#             */
/*   Updated: 2024/07/12 11:39:53 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deallocation(t_stack **a)
{
	t_stack	*node;
	t_stack	*tem;

	if (a == NULL)
		return ;
	node = *a;
	while (node)
	{
		tem = node->next;
		free(node);
		node = tem;
	}
	*a = NULL;
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

bool	syntax_error(const char *str)
{
	if (*str == '\0')
		return (true);
	if (*str == '+' || *str == '-')
		str++;
	if (*str < '0' || *str > '9')
		return (true);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (true);
		str++;
	}
	return (false);
}

void	dealloc(t_stack **a, char **argv, bool argc)
{
	deallocation(a);
	if (argc)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	repeated_num(t_stack *stack, int num)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->nbr == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}
