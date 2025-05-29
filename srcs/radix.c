/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:50:21 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 10:02:32 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"

// -------------------- RADIX ALORITHM -------------------------
//
// 1 - Check the len of bits of the biggest int in the starting stack 
//
// 2 - Compare each bits of each elements starting from the "right"
// this is the main counter
//
// 3 - A) In the first stack where all elements are (stack_a)
//        While the size of stack_a compare the first bit of the top of the
//        stack_a 
//        	- if the bit is == 1 : rotate 
//        	- if the bit is == 0 : push in the stack_b
//     -------- RADIX OPTI --------   	
//     B) In the stack_b to have one step ahead do the same thing with
//     	  stack_b
//     	    - if the next bit to check (i + 1) == 1 : push
//     	    - if not : rotate
//     	  It avoids to push in stack_a to re-push in stack_b 
//     	  Less operations...
// 4 - Finally when all the bits of all stacks are compared and all
// elements are stored put everything in the stack_a and returned
// the sorted stack

void	bit_sort(int i, int stack_a[], int stack_b[], int sizes[])
{
	int	nb_elements;

	nb_elements = sizes[A];
	while (nb_elements > 0)
	{
		if ((stack_a[0] >> i) & 1)
			ft_rotate(stack_a, sizes[A] - 1, 'a');
		else
		{
			ft_push(stack_a, stack_b, sizes[A] - 1, sizes[B]);
			write(1, "pb\n", 3);
			sizes[B]++;
			sizes[A]--;
		}
		nb_elements--;
	}
}

void	bit_sort_opti(int i, int stack_a[], int stack_b[], int sizes[])
{
	int	nb_elements;

	nb_elements = sizes[B];
	while (nb_elements > 0)
	{
		if ((stack_b[0] >> (i + 1)) & 1)
		{
			ft_push(stack_b, stack_a, sizes[B] - 1, sizes[A]);
			write(1, "pa\n", 3);
			sizes[B]--;
			sizes[A]++;
		}
		else
			ft_rotate(stack_b, sizes[B] - 1, 'b');
		nb_elements--;
	}
}

int	*radix(int stack_a[], int stack_b[], int sizes[])
{
	int	nb_bits;
	int	i;

	nb_bits = 0;
	i = 0;
	while ((sizes[A] - 1) >> nb_bits != 0)
		nb_bits++;
	while (i < nb_bits)
	{
		bit_sort(i, stack_a, stack_b, sizes);
		bit_sort_opti(i, stack_a, stack_b, sizes);
		i++;
	}
	while (sizes[B] > 0)
	{
		ft_push(stack_b, stack_a, sizes[B] - 1, sizes[A]);
		write(1, "pa\n", 3);
		sizes[B]--;
		sizes[A]++;
	}
	free(sizes);
	return (stack_a);
}
