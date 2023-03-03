/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:16:29 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 16:13:20 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_StackI *stack)
{
	if (stack->top > 0)
	{
		while (stack->top)
			pop(stack, &stack->first);
	}
	free(stack);
}

void	stack_clone(t_Stack *dst, t_Stack *src, int all)
{
	dst->data = src->data;
	dst->index = src->index;
	if (all)
	{
		dst->next = src->next;
		dst->prev = dst->prev;
		return ;
	}
	dst->next = NULL;
	dst->prev = NULL;
}

void	empty_stack(t_StackI *istack)
{
	if (!istack)
		return ;
	istack->first = NULL;
	istack->last = NULL;
}

void	pop(t_StackI *istack, t_Stack **p_stack)
{
	t_Stack	*stack;

	stack = *p_stack;
	if (!istack || !stack)
		return ;
	if (stack->next->data == stack->data)
		empty_stack(istack);
	else
	{
		if (istack->first->data == stack->data)
			istack->first = stack->next;
		else if (istack->last->data == stack->data)
			istack->last = stack->prev;
		stack->next->prev = stack->prev;
		stack->prev->next = stack->next;
	}
	istack->top--;
	do_free((void *)&stack, 0);
}

void	push(t_StackI *istack, t_Stack *stack)
{
	t_Stack	*cpy;

	cpy = (t_Stack *)malloc (sizeof(*cpy));
	if (!cpy)
		return ;
	stack_clone(cpy, stack, 0);
	istack->top++;
	if (!istack->first)
	{
		istack->first = cpy;
		istack->last = cpy;
		istack->first->next = istack->first;
		istack->first->prev = istack->last;
		return ;
	}
	istack->first->prev = cpy;
	istack->last->next = cpy;
	cpy->next = istack->first;
	cpy->prev = istack->last;
	istack->first = cpy;
}
