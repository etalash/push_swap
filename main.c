/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:38:46 by stalash           #+#    #+#             */
/*   Updated: 2024/08/21 13:12:05 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack	*create_node(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->nbr = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

static void	appened_to_stack_a(t_stack **a_stack, int num)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (a_stack == NULL)
		return ;
	new_node = create_node(num);
	if (*a_stack == NULL)
	{
		*a_stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_lst_last(*a_stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	add_to_stack_a(t_stack **a, char **argv, bool argc)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (syntax_error(argv[i]) == true)
			dealloc(a, argv, argc);
		num = ft_atol((const char *)argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			dealloc(a, argv, argc);
		if (repeated_num(*a, (int)num) == 1)
			dealloc(a, argv, argc);
		appened_to_stack_a(a, (int)num);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	if (argc == 2)
	{
		argv = s_split(argv[1], ' ');
		argv--;
	}
	add_to_stack_a(&a, argv + 1, argc == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			simple_sort(&a);
		else if (stack_len(a) == 3)
			simple_sort(&a);
		else
			push_swap(&a, &b);
	}
	deallocation(&a);
}
