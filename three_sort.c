/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:44:35 by iait-ouf          #+#    #+#             */
/*   Updated: 2023/12/17 17:48:29 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Hardcode for each 1 2 3 possible permutations, only using stack a
// -----------
// If 1, 2, 3, 4 -> exit 0, stop the program no return
// -----------
// 1, 3, 2 = rra -> 2, 1, 3 + sa -> 1, 2, 3
// -----------
// 2, 1, 3 = sa  -> 1, 2, 3
// -----------
// 2, 3, 1 = rra -> 1, 2, 3
// -----------
// 3, 1, 2 = ra  -> 1, 2, 3
// -----------
// 3, 2, 1 = ra  -> 2, 1, 3 + sa -> 1, 2, 3

void	three_sort(int stack[])
{
	if (ft_check_order(stack, 2) == SORTED)
		return ;
	if ((stack[0] < stack[1]) && (stack[1] > stack[2]) && (stack[0] < stack[2]))
	{
		ft_reverse_rotate(stack, 2, 'a');
		ft_swap(stack, 'a');
	}
	if ((stack[0] > stack[1]) && (stack[1] < stack[2]) && (stack[2] > stack[0]))
		ft_swap(stack, 'a');
	if ((stack[0] < stack[1]) && (stack[1] > stack[2]) && (stack[2] < stack[0]))
		ft_reverse_rotate(stack, 2, 'a');
	if ((stack[0] > stack[1]) && (stack[1] < stack[2]) && (stack[2] < stack[0]))
		ft_rotate(stack, 2, 'a');
	if ((stack[0] > stack[1]) && (stack[1] > stack[2]) && (stack[2] < stack[0]))
	{
		ft_rotate(stack, 2, 'a');
		ft_swap(stack, 'a');
	}
}
