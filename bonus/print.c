/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:49:34 by armartir          #+#    #+#             */
/*   Updated: 2023/02/27 21:03:51 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

void	print_c(char c, char name)
{
	write (1, &c, 1);
	write (1, &name, 1);
	write (1, "\n", 1);
}

void	print_add(char c, char name, char add)
{
	write (1, &c, 1);
	write (1, &name, 1);
	write (1, &add, 1);
	write (1, "\n", 1);
}
