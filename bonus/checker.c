/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:01:08 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 16:09:15 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"
#include <stdio.h>

void	select_action(t_StackI *a, t_StackI *b, char *line)
{
	if (ft_strncmp(line, "sa", 2))
		swap (a, 0);
	else if (ft_strncmp(line, "sb", 2))
		swap (b, 0);
	else if (ft_strncmp(line, "ss", 2))
		swap_both(a, b, 0);
	else if (ft_strncmp(line, "pa", 2))
		push_stack(&b, a, 0);
	else if (ft_strncmp(line, "pb", 2))
		push_stack(&a, b, 0);
	else if (ft_strncmp(line, "rra", 3))
		reverse (a, 0);
	else if (ft_strncmp(line, "rrb", 3))
		reverse (b, 0);
	else if (ft_strncmp (line, "rrr", 3))
		reverse_both (a, b, 0);
	else if (ft_strncmp (line, "ra", 2))
		rotate (a, 0);
	else if (ft_strncmp(line, "rb", 2))
		rotate (b, 0);
	else if (ft_strncmp (line, "rr", 2))
		rotate_both(a, b, 0);
	else
		print_error();
	free (line);
}

void	ko_msg(void)
{
	write (2, "KO\n", 3);
	exit (1);
}

int	check_sort(t_StackI *istack)
{
	t_Stack	*stack_a;

	stack_a = istack->first;
	while (stack_a != istack->last)
	{
		if (stack_a->data > stack_a->next->data)
			ko_msg();
		stack_a = stack_a->next;
	}
	return (0);
}

int	check_ps(t_StackI *istack)
{
	char		*tmp;
	int			is_sorted;
	t_StackI	*stack_b;

	stack_b = init_stack('b');
	tmp = get_next_line(0);
	while (tmp)
	{
		select_action (istack, stack_b, tmp);
		tmp = get_next_line(0);
		if (ft_strncmp(tmp, "\n", 1))
		{
			free (tmp);
			break ;
		}
	}
	is_sorted = check_sort(istack);
	free_stack (istack);
	free_stack (stack_b);
	return (is_sorted);
}

int	main(int argc, char **argv)
{
	size_t		real_l;
	int			*nums;
	t_StackI	*istack;

	if (argc < 2)
		return (0);
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
	}
	else
		print_error();
	if (!(check_ps(istack)))
		write (1, "OK\n", 3);
	return (0);
}
