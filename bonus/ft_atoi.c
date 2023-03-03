/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:42:35 by armartir          #+#    #+#             */
/*   Updated: 2023/01/18 14:42:40 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*check(char *str)
{
	if (*(str + 1) && *str == '0')
	{
		while (*str && *str == '0')
			str++;
		return (str);
	}
	return (str);
}

int	ft_atoi(char *str, char **splited)
{
	long		nbr;
	int			isneg;

	nbr = 0;
	isneg = 1;
	if (*str == '-')
		isneg = -1;
	if (*str == '-' || *str == '+')
		str++;
	str = check(str);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			do_free(0, splited);
			splited = 0x0;
			print_error();
		}
		nbr = ((nbr * 10) + (*str - '0'));
		str++;
	}
	if ((isneg == -1 && nbr <= INT_MIN) || nbr <= INT_MAX)
		return ((int)(nbr * isneg));
	print_error();
	return (0);
}
