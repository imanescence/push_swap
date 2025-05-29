/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:44:12 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 10:02:23 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"

int	*ar_dup(int stack[], int size)
{
	int	i;
	int	*ar_dup;

	i = 0;
	ar_dup = malloc(size * sizeof(int));
	if (ar_dup == NULL)
		return (NULL);
	while (i < size)
	{
		ar_dup[i] = stack[i];
		i++;
	}
	return (ar_dup);
}

int	*bubble_sort(int tmp_sorted[], int size)
{
	int	tmp;
	int	i;
	int	j;

	tmp = 0;
	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (tmp_sorted[j] > tmp_sorted[j + 1])
			{
				tmp = tmp_sorted[j];
				tmp_sorted[j] = tmp_sorted[j + 1];
				tmp_sorted[j + 1] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	return (tmp_sorted);
}

int	*replace_values(int stack_a[], int stack_b[], int size)
{
	int	i;
	int	j;
	int	*ar_sorted;
	int	*new_stack;

	i = 0;
	j = i + 1;
	ar_sorted = ar_dup(stack_a, size);
	new_stack = malloc(size * sizeof(int));
	if (!ar_sorted || !new_stack)
		free_me(stack_a, stack_b, EXIT_ERROR);
	ar_sorted = bubble_sort(ar_sorted, size);
	while (i < size)
	{
		while (j < size)
		{
			if (ar_sorted[j] == stack_a[i])
				new_stack[i] = j;
			j++;
		}
		j = 0;
		i++;
	}
	free(ar_sorted);
	return (new_stack);
}
