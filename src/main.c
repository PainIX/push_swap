/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:21:03 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 15:48:39 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_StackI	*init_stack(char name)
{
	t_StackI	*stack;

	stack = (t_StackI *)malloc(sizeof(t_StackI));
	if (!stack)
		return (NULL);
	stack->first = NULL;
	stack->last = NULL;
	stack->top = 0;
	stack->name = name;
	stack->error = 0;
	return (stack);
}

int	sorting(t_StackI *stack_a)
{
	t_StackI	*stack_b;

	stack_b = init_stack('b');
	if (!stack_b)
		return (0);
	select_algorithm(stack_a, stack_b);
	free_stack (stack_a);
	free_stack (stack_b);
	return (1);
}

int	main(int argc, char **argv)
{
	size_t		real_l;
	int			*nums;
	t_StackI	*istack;

	istack = init_stack('a');
	if (!istack || argc <= 1)
		return (1);
	real_l = validation(argc, argv);
	if (real_l)
	{
		nums = get_nums(argc, argv, real_l);
		if (!nums)
			print_error();
		create_stack(nums, real_l, istack);
		if (!sorting(istack))
			return (1);
	}
	else
		print_error();
	return (0);
}
