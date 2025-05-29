/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:39:54 by iait-ouf          #+#    #+#             */
/*   Updated: 2023/12/17 18:54:01 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define SORTED 0

# define UNSORTED -1

# define EXIT_ERROR 1

# define EXIT_OK 0 

# define A 0

# define B 1

# define NB_ELMTS 2

# define NO_CORRECT 110 

// ------------- MINISORT -----------------
void	three_sort(int stack[]);
void	four_sort_first(int stack_a[], int stack_b[]);
void	four_sort_second(int stack_a[], int stack_b[]);
void	five_sort_second(int stack_a[], int stack_b[]);
void	five_sort_first(int stack_a[], int stack_b[]);
void	five_sort_third(int stack_a[], int stack_b[]);

// ------------ PARSING UTILS --------------
int		ft_check_order(int stack[], int size);
int		ft_check_tab(int stack_a[], int stack_b[], int size);
int		ft_atol(char *str, int stack_a[], int stack_b[]);
int		ft_isdigit(int c);
char	ft_str_isdigit(char *str);

// ------------- OPERATIONS ---------------
void	ft_swap(int stack[], char flag);
void	ft_double_swap(int stack_a[], int stack_b[]);
void	ft_push(int s_pulled[], int s_pushed[], int size_pull, int size_push);
void	ft_rotate(int stack[], int size, char flag);
void	ft_reverse_rotate(int stack[], int size, char flag);

// ------------ ERROR MANAGEMENT -----------
int		free_me(void *ptr1, void *ptr2, int flag);
int		ft_error(void *ptr1, void *ptr2);

// ------------ MAIN & CALLING FUNCTIONS -----
int		main(int argc, char **argv);
void	mini_sort(int stack_a[], int stack_b[], int nb_elements);
void	big_sort(int stack_a[], int stack_b[], int nb_elements);

// ------------- PRE-SORT ---------------------
int		*replace_values(int stack_a[], int stack_b[], int size);
int		*bubble_sort(int tmp_sorted[], int size);
int		*ar_dup(int stack[], int size);

// ------------- RADIX ALGORITHM --------------
int		*radix(int stack_a[], int stack_b[], int sizes[]);

#endif
