/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:31:15 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 16:13:27 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_StackI *stack1, t_StackI *stack2, short idc)
{
	rotate (stack1, 0);
	rotate (stack2, 0);
	if (idc)
		print_c ('r', 'r');
}

void	rotate(t_StackI *stack, short idc)
{
	if (stack->top > 1 && stack->first && stack->last)
	{
		stack->first = stack->first->next;
		stack->last = stack->last->next;
	}
	if (idc)
		print_c('r', stack->name);
}
