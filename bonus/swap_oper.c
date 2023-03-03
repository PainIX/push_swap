/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:54:55 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 16:13:32 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_StackI *stack_a, t_StackI *stack_b, short idc)
{
	swap (stack_a, 0);
	swap (stack_b, 0);
	if (idc)
		print_c('s', 's');
}

void	swap(t_StackI *stack, short idc)
{
	t_Stack	*list;
	int		temp_data;
	size_t	temp_index;

	list = stack->first;
	if (!list || list->next->data == list->data)
		return ;
	temp_data = list->data;
	temp_index = list->index;
	list->data = list->next->data;
	list->index = list->next->index;
	list->next->data = temp_data;
	list->next->index = temp_index;
	if (idc)
		print_c('s', stack->name);
}
