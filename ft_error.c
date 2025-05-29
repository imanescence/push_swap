/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:07:17 by iait-ouf          #+#    #+#             */
/*   Updated: 2023/12/17 12:29:07 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void *ptr1, void *ptr2)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (free_me(ptr1, ptr2, EXIT_ERROR));
}
