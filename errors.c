/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:25:49 by stalash           #+#    #+#             */
/*   Updated: 2024/06/11 19:21:58 by stalash          ###   ########.fr       */
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

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv - 1);
}

int	syntax_error(char *argv)
{
	int	i;

	i = 0;
	if (!(argv[i] == '+' || argv[i] == '-' \
			|| (argv[i] >= '0' && argv[i] <= '9')))
		return (1);
	if (argv[i] == '-' || (argv[i] == '+' \
			&& !(argv[i + 1] >= '0' && argv[i + 1] <= '9')))
		return (1);
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
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
