/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:58:16 by iait-ouf          #+#    #+#             */
/*   Updated: 2025/05/29 10:00:07 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"

int	free_me(void *ptr1, void *ptr2, int flag)
{
	free(ptr1);
	free(ptr2);
	if (flag == EXIT_ERROR)
		exit (1);
	else
		exit (0);
}
