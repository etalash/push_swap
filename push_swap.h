/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:31:02 by stalash           #+#    #+#             */
/*   Updated: 2024/06/03 18:09:28 by stalash          ###   ########.fr       */
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

#endif
