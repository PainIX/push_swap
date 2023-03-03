/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:07:13 by armartir          #+#    #+#             */
/*   Updated: 2023/02/28 15:19:10 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_free(void **address, char **address_2d)
{
	int	i;

	i = -1;
	if (address)
	{
		free (*address);
		*address = 0x0;
	}
	if (address_2d)
	{
		while (address_2d[++i])
			free (address_2d[i]);
		free(address_2d);
	}
}

size_t	validation(int argc, char **argv)
{
	size_t		len;
	size_t		i;
	char		**numbers;

	len = 0;
	while (--argc)
	{
		i = 0;
		numbers = ft_split(argv[argc], ' ');
		if (!numbers)
			return (0);
		while (numbers[i])
		{
			len++;
			i++;
		}
		do_free(0, numbers);
		numbers = 0x0;
	}
	return (len);
}

int	check_doubles(int *numbers, size_t real_l)
{
	size_t		i;
	size_t		tmp;

	i = 0;
	while (i < real_l)
	{
		tmp = i + 1;
		while (tmp < real_l)
		{
			if (numbers[i] == numbers[tmp])
				return (0);
			tmp++;
		}
		i++;
	}
	return (1);
}

int	*get_nums(int argc, char **argv, size_t real_l)
{
	int			*rt_num;
	char		**str;
	size_t		tmp;
	size_t		i;

	tmp = real_l - 1;
	rt_num = (int *)malloc(sizeof(int) * real_l);
	if (!rt_num)
		print_error();
	while (--argc)
	{
		i = 0;
		str = ft_split(argv[argc], ' ');
		if (!str)
			return (0);
		while (str[i])
			i++;
		while (i > 0)
			rt_num[tmp--] = ft_atoi(str[--i], 0);
		do_free(0, str);
		str = 0x0;
	}
	if (!check_doubles(rt_num, real_l))
		print_error();
	return (rt_num);
}
