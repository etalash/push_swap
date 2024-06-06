/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:38:46 by stalash           #+#    #+#             */
/*   Updated: 2024/06/06 17:44:29 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_push_swap	*ft_lst_last(t_list_push_swap *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_list_push_swap	*create_node(int num)
{
	t_list_push_swap	*new_node;

	new_node = (t_list_push_swap *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->nbr = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

static void	appened_to_stack_a(t_list_push_swap **a_stack, int num)
{
	t_list_push_swap	*new_node;
	t_list_push_swap	*last_node;

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

void	add_to_stack_a(t_list_push_swap **a, char **argv)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (syntax_error(argv[i]) == 1)
		{
			printf("there are syntax errors in the function\n");
			return ;
			//realloc(a); // make this functioin
		}
		num = ft_atol((const char *)argv[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			printf("the number is above or under the integer limits\n");
			return ;
			//realloc(a); // also
		}
		appened_to_stack_a(a, (int)num);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list_push_swap	*a;
	t_list_push_swap	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	// if (argc == 2)
	// 	argv = ft_split(argv[1], 32);
	add_to_stack_a(&a, argv + 1);
	if (sorted_stack(a) != 1)
	{
		if (argc == 4)
		{
			sort_three(a);
			printf("the params are sorted\n");
		}
	// 	else if (argc == 5)
	// 		sort_five(a);
	// 	else
	// 		sort_param(a, b);
	}
	return (0);
}
