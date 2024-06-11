/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:31:02 by stalash           #+#    #+#             */
/*   Updated: 2024/06/11 21:54:09 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct s_list_push_swap
{
	int						nbr;
	struct s_list_push_swap	*prev;
	struct s_list_push_swap	*next;
}				t_stack;

// errors, and some other subordinate functions

int		syntax_error(char *argv);
int		sorted_stack(t_stack *a);
void	sort_three(t_stack *a);
long	ft_atol(const char *s);
char	**s_split(char const *s, char c);
void	deallocation(t_stack **a);
void	dealloc(t_stack **a, char **argv, bool argc);
int		repeated_num(t_stack *stack, int num);
int		stack_len(t_stack *stack);

// swap, rotate, revers_rotate, push

void	sa(t_stack **a, bool check);
void	sb(t_stack **b, bool check);
void	ss(t_stack **a, t_stack **b, bool check);
void	ra(t_stack **a, bool check);
void	rb(t_stack **b, bool check);
void	rr(t_stack **a, t_stack **b, bool check);
void	rra(t_stack **a, bool check);
void	rrb(t_stack **b, bool check);
void	rrr(t_stack **a, t_stack **b, bool check);

#endif
