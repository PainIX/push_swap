/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:28:37 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 15:45:09 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct Stack {
	int				data;
	size_t			index;
	struct Stack	*prev;
	struct Stack	*next;
}	t_Stack;

typedef struct StackInterface
{
	size_t			top;
	struct Stack	*first;
	struct Stack	*last;
	char			name;
	short			error;
}	t_StackI;

void	print_c(char c, char name);
void	empty_stack(t_StackI *istack);
void	swap(t_StackI *stack, short idc);
void	rotate(t_StackI *stack, short idc);
void	reverse(t_StackI *stack, short idc);
void	push(t_StackI *istack, t_Stack *stack);
void	print_add(char c, char name, char add);
void	pop(t_StackI *istack, t_Stack **p_stack);
void	stack_clone(t_Stack *dst, t_Stack *src, int all);
void	rotate_both(t_StackI *stack1, t_StackI *stack2, short idc);
void	swap_both(t_StackI *stack_a, t_StackI *stack_b, short idc);
void	push_stack(t_StackI **istack, t_StackI *stack, short idc);
void	reverse_both(t_StackI *stack1, t_StackI *stack2, short idc);

#endif