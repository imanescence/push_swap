/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:01 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 10:01:47 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"

void	mini_sort(int stack_a[], int stack_b[], int nb_elements)
{
	if (nb_elements == 2)
		ft_swap(stack_a, 'a');
	else if (nb_elements == 3)
		three_sort(stack_a);
	else if (nb_elements == 4)
		four_sort_first(stack_a, stack_b);
	else
		five_sort_first(stack_a, stack_b);
}

void	big_sort(int stack_a[], int stack_b[], int nb_elements)
{
	int	*new_stack;
	int	*sizes;

	sizes = malloc(2 * sizeof(int));
	if (!sizes)
		free_me(stack_a, stack_b, EXIT_ERROR);
	new_stack = replace_values(stack_a, stack_b, nb_elements);
	sizes[A] = nb_elements;
	sizes[B] = 0;
	new_stack = radix(new_stack, stack_b, sizes);
}

int	main(int argc, char **argv)
{
	int	n;
	int	*stack_a;
	int	*stack_b;

	n = argc - 1;
	stack_a = malloc(n * sizeof(int));
	stack_b = malloc(n * sizeof(int));
	if (stack_a == NULL || stack_b == NULL)
		free_me(stack_a, stack_b, EXIT_ERROR);
	if (n > 1)
	{
		while (n--)
			stack_a[n] = ft_atol(argv[n + 1], stack_a, stack_b);
		n = argc - 2;
		ft_check_tab(stack_a, stack_b, n);
		if (ft_check_order(stack_a, n) == SORTED)
			free_me(stack_a, stack_b, EXIT_OK);
		if (argc - 1 >= 2 && argc - 1 <= 5)
			mini_sort(stack_a, stack_b, argc - 1);
	}
	if ((argc - 1) > 5)
		big_sort(stack_a, stack_b, (argc - 1));
	free_me(stack_a, stack_b, EXIT_OK);
}
