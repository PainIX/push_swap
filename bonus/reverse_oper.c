/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_oper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:04:47 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 14:16:29 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_both(t_StackI *stack1, t_StackI *stack2, short idc)
{
	reverse (stack1, 0);
	reverse (stack2, 0);
	if (idc)
		print_add ('r', 'r', 'r');
}

void	reverse(t_StackI *stack, short idc)
{
	if (stack->top > 1 && stack->first && stack->last)
	{
		stack->first = stack->first->prev;
		stack->last = stack->last->prev;
	}
	if (idc)
		print_add('r', 'r', stack->name);
}
