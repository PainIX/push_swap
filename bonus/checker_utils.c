/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:04:45 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 15:58:20 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
