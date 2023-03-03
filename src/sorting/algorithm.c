/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:38:21 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 15:49:41 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algorithm(t_StackI *stack_a, t_StackI *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->top == 1)
		return ;
	if (stack_a->top == 2)
	{
		if (stack_a->first->data > stack_a->last->data)
			swap (stack_a, 1);
		return ;
	}
	if (stack_a->top == 3)
	{
		sort_3(stack_a);
		return ;
	}
	if (is_sorted(stack_a) || is_sequence(stack_a))
		return ;
	butterfly (stack_a, stack_b);
}

void	sort_3(t_StackI *stack_a)
{
	t_Stack	*list;

	list = stack_a->first;
	if (list->index > list->next->index && list->index > list->prev->index)
		rotate(stack_a, 1);
	else if (list->next->index > list->index
		&& list->next->index > list->prev->index)
		reverse(stack_a, 1);
	if (stack_a->first->index > stack_a->first->next->index)
		swap(stack_a, 1);
}

short	is_sorted(t_StackI *stack)
{
	t_Stack		*cur;
	size_t		cur_num;

	cur = stack->first->next;
	cur_num = stack->first->index;
	while (cur->index != stack->first->index)
	{
		if (cur->index != (cur_num + 1))
			return (0);
		cur_num = cur->index;
		cur = cur->next;
	}
	return (1);
}

short	is_sequence(t_StackI *stack)
{
	size_t	index;
	t_Stack	*list;

	index = 0;
	list = stack->first;
	while (list->index != 0)
	{
		list = list->next;
		index++;
	}
	while (list->next->index != 0)
	{
		if (!((list->index + 1) == list->next->index))
			return (0);
		list = list->next;
	}
	while (index)
	{
		rotate (stack, 1);
		index--;
	}
	return (1);
}
