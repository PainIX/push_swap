/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:37:08 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 16:14:32 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN 2147483648

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "stack.h"

int			sorting(t_StackI *stack_a);
int			ft_atoi(char *str, char **splited);
int			check_doubles(int *numbers, size_t real_l);
int			*get_nums(int argc, char **argv, size_t real_l);

void		print_error(void);
void		sort_3(t_StackI *stack_a);
void		free_stack(t_StackI *stack);
void		sort_list(int *nums, size_t size);
void		go_top(t_StackI *stack, t_Stack *cur);
void		do_free(void **address, char **address_2d);
void		butterfly(t_StackI *stack_a, t_StackI *stack_b);
void		small_sort(t_StackI *stack_a, t_StackI *stack_b);
void		indexing(int *nums, size_t size, t_Stack *stack);
void		create_stack(int *nums, size_t size, t_StackI *istack);
void		select_algorithm(t_StackI *stack_a, t_StackI *stack_b);
void		butterfly_reverse(t_StackI *stack_a, t_StackI *stack_b);
void		stack_u(t_StackI *istack, t_Stack *cur, t_Stack *prev, size_t size);

char		*check(char *str);
char		**ft_split(char const *s, char c);

short		is_sorted(t_StackI *stack);
short		is_sequence(t_StackI *stack);

size_t		get_n(size_t i);
size_t		ft_ln(size_t nb);
size_t		ft_sqrt(size_t nb);
size_t		validation(int argc, char **argv);

t_StackI	*init_stack(char name);

#endif