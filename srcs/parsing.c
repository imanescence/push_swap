/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:25:33 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 10:02:13 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"

int	ft_atol(char *str, int stack_a[], int stack_b[])
{
	int		i;
	long	nb;
	long	ng;

	i = 0;
	nb = 0;
	ng = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			ng *= -1;
		i++;
	}
	if (ft_str_isdigit(str) == NO_CORRECT)
		return (ft_error(stack_a, stack_b));
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10;
		nb = nb + (str[i++] - '0');
	}
	if ((nb * ng) > INT_MAX || (nb * ng) < INT_MIN)
		return (ft_error(stack_a, stack_b));
	return ((int)(nb * ng));
}

int	ft_check_tab(int stack_a[], int stack_b[], int size)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i < size)
	{
		while (j <= size)
		{
			if (stack_a[i] == stack_a[j])
				return (ft_error(stack_a, stack_b));
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	ft_check_order(int stack[], int size)
{
	while (size > 0)
	{
		if (stack[size] < stack[size - 1])
			return (UNSORTED);
		size--;
	}
	return (SORTED);
}
