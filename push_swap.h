/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:31:02 by stalash           #+#    #+#             */
/*   Updated: 2024/06/06 17:43:15 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_list_push_swap
{
	int						nbr;
	struct s_list_push_swap	*prev;
	struct s_list_push_swap	*next;
}				t_list_push_swap;

int		syntax_error(char *argv);
void	swap(t_list_push_swap *stack);
int		sorted_stack(t_list_push_swap *a);
void	sort_three(t_list_push_swap *a);
long	ft_atol(const char *s);

#endif
