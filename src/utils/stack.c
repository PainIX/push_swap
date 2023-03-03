/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:08:53 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 16:13:51 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(int *nums, size_t size)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (i < size - 1)
	{
		if (nums[i] > nums[i + 1])
		{
			tmp = nums[i + 1];
			nums[i + 1] = nums[i];
			nums[i] = tmp;
			i = 0;
			continue ;
		}
		i++;
	}
}

void	indexing(int *nums, size_t size, t_Stack *stack)
{
	size_t	i;
	size_t	j;
	t_Stack	*head;

	i = 0;
	head = stack;
	while (i < size)
	{
		j = 0;
		stack = head;
		while (j < size)
		{
			if (nums[i] == stack->data)
			{
				stack->index = i;
				break ;
			}
			stack = stack->next;
			j++;
		}
		i++;
	}
}

void	stack_u(t_StackI *istack, t_Stack *cur, t_Stack *prev, size_t size)
{
	if (!istack || !cur)
		return ;
	if (istack->top == 0)
		istack->first = cur;
	else
	{
		prev->next = cur;
		cur->prev = prev;
	}
	if (istack->top == size - 1)
	{
		istack->last = cur;
		istack->first->prev = istack->last;
		cur->next = istack->first;
	}
}

void	create_stack(int *nums, size_t size, t_StackI *istack)
{
	t_Stack	*stack;
	t_Stack	*temp;

	istack->top = 0;
	temp = NULL;
	while (istack->top < size)
	{
		stack = (t_Stack *)malloc(sizeof(*stack));
		if (!stack)
		{
			free(nums);
			istack->error = 1;
			return ;
		}
		stack->data = nums[istack->top];
		stack_u(istack, stack, temp, size);
		temp = stack;
		istack->top++;
	}
	if (stack)
	{
		sort_list(nums, size);
		indexing(nums, size, stack);
	}
	free (nums);
}
