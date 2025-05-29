/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:17:26 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 10:01:56 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"

// Manage a sort with 4 args only using stack a and stack_b
// -----------------
// If 1, 2, 3, 4 return directly mini sort which exit 0 and returns nothing
// -----------------
// If the smallest element is at the last position like 2, 4, 3, 1
// do a rra   -> stack_a = 1, 2, 4, 3
// do a pb    -> stack_a = 2, 4, 3     & stack_b = 1
// do a 3sort -> stack_a = 2, 3, 4     & stack_b = 1
// do a pa    -> stack_a = 1, 2, 3, 4  & stack_b = \
// -----------------
// If the smallest element is at the first position like 1, 3, 4, 2 
// do a pb    -> stack_a = 3, 4, 2    & stack_b = 1
// do a 3sort -> stack_a = 2, 3, 4
// do a pa    -> stack_a = 1, 2, 3, 4 & stack_b = \
// -----------------
// If the smallest element is at the second position like 4, 1, 2, 3
// do a sa    -> stack_a = 1, 4, 2, 3
// do a pb    -> stack_a = 4, 2, 3    & stack_b = 1
// do a 3sort -> stack_a = 2, 3, 4    & stack_b = 1
// do a pa    -> stack_a = 1, 2, 3, 4 & stack_b = \
// -----------------
// If the smallest element is at the third position like 3, 2, 1, 4 
// do a rra   -> stack_a = 4, 3, 2, 1
// do a rra   -> stack_a = 1, 4, 3, 2
// do a pb    -> stack_a = 4, 3, 2    & stack_b = 1
// do a 3sort -> stack_a = 2, 3, 4    & stack_b = 1
// do a pa    -> stack_a = 1, 2, 3, 4 & stack_b = /

void	four_sort_second(int stack_a[], int stack_b[])
{
	if ((stack_a[1] < stack_a[0]) && (stack_a[1] < stack_a[2])
		&& (stack_a[1] < stack_a[3]))
	{
		ft_rotate(stack_a, 3, 'a');
		if (ft_check_order(stack_a, 3) == SORTED)
			return ;
		ft_push(stack_a, stack_b, 3, 0);
		write(1, "pb\n", 3);
		three_sort(stack_a);
		ft_push(stack_b, stack_a, 0, 2);
		write(1, "pa\n", 3);
	}
	else
	{
		ft_reverse_rotate(stack_a, 3, 'a');
		ft_reverse_rotate(stack_a, 3, 'a');
		if (ft_check_order(stack_a, 3) == SORTED)
			return ;
		ft_push(stack_a, stack_b, 3, 0);
		write(1, "pb\n", 3);
		three_sort(stack_a);
		ft_push(stack_b, stack_a, 0, 2);
		write(1, "pa\n", 3);
	}
}

void	four_sort_first(int stack_a[], int stack_b[])
{
	if ((stack_a[3] < stack_a[2]) && (stack_a[3] < stack_a[1])
		&& (stack_a[3] < stack_a[0]))
	{
		ft_reverse_rotate(stack_a, 3, 'a');
		if (ft_check_order(stack_a, 3) == SORTED)
			return ;
		ft_push(stack_a, stack_b, 3, 0);
		write(1, "pb\n", 3);
		three_sort(stack_a);
		ft_push(stack_b, stack_a, 0, 2);
		write(1, "pa\n", 3);
	}
	else if ((stack_a[0] < stack_a[1]) && (stack_a[0] < stack_a[2]) 
		&& (stack_a[0] < stack_a[3]))
	{
		ft_push(stack_a, stack_b, 3, 0);
		write(1, "pb\n", 3);
		three_sort(stack_a);
		ft_push(stack_b, stack_a, 0, 2);
		write(1, "pa\n", 3);
	}
	else 
		four_sort_second(stack_a, stack_b);
}

// Manage a sort with 5 args which finds the smallest element 
// pushed at the top of 
// stack a, then pulled and pushed in the stack b, 
// call the four_sort who manage 
// the stack a with 4 elements (which call the three sort), 
// finish by the smallest of the 5 elements pushed in the stack a
// ---------------
// If the smallest element is at the last position like 4, 5, 3, 2, 1
// do a rra   -> stack_a = 1, 4, 5, 3, 2
// check if right order
// do a pb    -> stack_a = 4, 5, 3, 2    & stack_b = 1
// do a 4sort -> stack_a = 2, 3, 4, 5    & stack_b = 1
// do a pa    -> stack_a = 1, 2, 3, 4, 5 & stack_b = /
// ---------------
// If the smallest element is at the first position like 1, 5, 4, 2, 3 
// do a pb    -> stack_a = 5, 4, 2, 3    & stack_b = 1 
// do a 4sort -> stack_a = 2, 3, 4, 5    & stack_b = 1
// do a pa    -> stack_a = 1, 2, 3, 4, 5 & stack_b = /
// ---------------
// If the smallest element is at the second position like 2, 1, 5, 3, 4
// do sa      -> stack_a = 1, 2, 5, 3, 4
// check if right order
// do a pb    -> stack_a = 2, 5, 3, 4    & stack_b = 1
// do a 4sort -> stack_a = 2, 3, 4, 5    & stack_b = 1
// do a pa    -> stack_a = 1, 2, 3, 4, 5 & stack_b = /
// ---------------
// If the smallest element is at the third position like 2, 4, 1, 3, 5 
// do a ra    -> stack_a = 4, 1, 3, 5, 2
// do a ra    -> stack_a = 1, 3, 5, 2, 4
// check if is the right order
// do a pb    -> stack_a = 3, 5, 2, 4    & stack_b = 1
// do a 4sort -> stack_a = 2, 3, 4, 5    & stack_b = 1
// do a pa    -> stack_a = 1, 2, 3, 4, 5 & stack_b = /
// ---------------
// If the smallest element is at the fourth position like 3, 2, 4, 1, 5
// do a rra   -> stack_a = 5, 3, 2, 4, 1
// do a rra   -> stack_a = 1, 5, 3, 2, 4
// check if is the right order
// do a pb    -> stack_a = 5, 3, 2, 4    & stack_b = 1
// do a 4sort -> stack_a = 1, 2, 3, 4, 5 & stack_b = /

void	five_sort_third(int stack_a[], int stack_b[])
{
	if ((stack_a[0] < stack_a[1]) && (stack_a[0] < stack_a[2])
		&& (stack_a[0] < stack_a[3]) && (stack_a[0] < stack_a[4]))
	{
		ft_push(stack_a, stack_b, 4, 0);
		write(1, "pb\n", 3);
		four_sort_first(stack_a, stack_b);
		ft_push(stack_b, stack_a, 0, 3);
		write(1, "pa\n", 3);
	}
	else
	{
		ft_swap(stack_a, 'a');
		if (ft_check_order(stack_a, 4) == SORTED)
			return ;
		ft_push(stack_a, stack_b, 4, 0);
		write(1, "pb\n", 3);
		four_sort_first(stack_a, stack_b);
		ft_push(stack_b, stack_a, 0, 3);
		write(1, "pa\n", 3);
	}
}

void	five_sort_second(int stack_a[], int stack_b[])
{
	if ((stack_a[2] < stack_a[0]) && (stack_a[2] < stack_a[1])
		&& (stack_a[2] < stack_a[3]) && (stack_a[2] < stack_a[4]))
	{
		ft_rotate(stack_a, 4, 'a');
		ft_rotate(stack_a, 4, 'a');
		if (ft_check_order(stack_a, 4) == SORTED)
			return ;
		ft_push(stack_a, stack_b, 4, 0);
		write(1, "pb\n", 3);
		four_sort_first(stack_a, stack_b);
		ft_push(stack_b, stack_a, 0, 3);
		write(1, "pa\n", 3);
	}
	else
	{
		ft_reverse_rotate(stack_a, 4, 'a');
		ft_reverse_rotate(stack_a, 4, 'a');
		if (ft_check_order(stack_a, 4) == SORTED)
			return ;
		ft_push(stack_a, stack_b, 4, 0);
		write(1, "pb\n", 3);
		four_sort_first(stack_a, stack_b);
		ft_push(stack_b, stack_a, 0, 3);
		write(1, "pa\n", 3);
	}
}

void	five_sort_first(int stack_a[], int stack_b[])
{
	if ((stack_a[4] < stack_a[0]) && (stack_a[4] < stack_a[1])
		&& (stack_a[4] < stack_a[2]) && (stack_a[4] < stack_a[3]))
	{
		ft_reverse_rotate(stack_a, 4, 'a');
		if (ft_check_order(stack_a, 4) == SORTED)
			return ;
		ft_push(stack_a, stack_b, 4, 0);
		write(1, "pb\n", 3);
		four_sort_first(stack_a, stack_b);
		ft_push(stack_b, stack_a, 0, 3);
		write(1, "pa\n", 3);
	}
	else if ((stack_a[0] < stack_a[1]) && (stack_a[0] < stack_a[2])
		&& (stack_a[0] < stack_a[3]) && (stack_a[0] < stack_a[4]))
		five_sort_third(stack_a, stack_b);
	else if ((stack_a[1] < stack_a[0]) && (stack_a[1] < stack_a[2])
		&& (stack_a[1] < stack_a[3]) && (stack_a[1] < stack_a[4]))
		five_sort_third(stack_a, stack_b);
	else if (stack_a[2] < stack_a[0] && stack_a[2] < stack_a[1]
		&& stack_a[2] < stack_a[3] && stack_a[2] < stack_a[4])
		five_sort_second(stack_a, stack_b);
	else
		five_sort_second(stack_a, stack_b);
}
