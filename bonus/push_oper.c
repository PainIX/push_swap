/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:36:25 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 14:34:01 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_StackI **istack, t_StackI *stack, short idc)
{
	t_StackI	*cpy;

	cpy = *istack;
	if (!cpy->first)
		return ;
	push (stack, cpy->first);
	pop (cpy, &cpy->first);
	if (idc)
		print_c ('p', stack->name);
}
