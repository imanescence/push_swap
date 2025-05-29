/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:13:27 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 10:02:05 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"

// -----------
// Swap the first 2 elements at the top of stack a or b. 
// Do nothing if there is no element in the stack.
// I'm using a flag a or b to identify which stack is called 
// and return the correct print value.
// -----------

void	ft_swap(int stack[], char flag)
{
	int	tmp;

	tmp = 0;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (flag == 'a')
		(write(1, "sa\n", 3));
	else
		(write(1, "sb\n", 3));
}

// ------------
// Swap the first two elements of stacks a and b at the same time.
// ------------

void	ft_double_swap(int stack_a[], int stack_b[])
{
	int	tmp;

	tmp = 0;
	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
	(write(1, "ss\n", 3));
}

// -----------
// Take the first element at the top of b and put it at the top of a 
// or the top of a to the top of b.
// Do nothing if the pulled stack is empty.
// -----------

void	ft_push(int s_pulled[], int s_pushed[], int size_pull, int size_push)
{
	int	tmp;
	int	i;

	tmp = s_pulled[0];
	i = 0;
	while (i < size_pull)
	{
		s_pulled[i] = s_pulled[i + 1];
		i++;
	}
	while (size_push > 0)
	{
		s_pushed[size_push] = s_pushed[size_push - 1];
		size_push--;
	}
	s_pushed[0] = tmp;
}

// ------------
// Shift up all elements of stack a by 1. 
// The first element becomes the last one.
// Once again using flag for the same reasons.
// ------------

void	ft_rotate(int stack[], int size, char flag)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack[0];
	while (size > i)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
	if (flag == 'a')
		(write(1, "ra\n", 3));
	else
		(write(1, "rb\n", 3));
}
// ------------
// Shift down all elements of stack a by 1. 
// The last element becomes the first one.
// ------------

void	ft_reverse_rotate(int stack[], int size, char flag)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack[size];
	while (size > 0)
	{
		stack[size] = stack[size - 1];
		size--;
	}
	stack[0] = tmp;
	if (flag == 'a')
		(write(1, "rra\n", 4));
	else
		(write(1, "rrb\n", 4));
}
