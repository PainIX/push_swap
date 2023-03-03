/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:01:30 by armartir          #+#    #+#             */
/*   Updated: 2023/03/02 16:14:18 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "stack.h"

size_t		validation(int argc, char **argv);
void		do_free(void **address, char **address_2d);
char		**ft_split(char const *s, char c);
int			*get_nums(int argc, char **argv, size_t real_l);
int			ft_atoi(char *str, char **splited);
char		*check(char *str);
int			check_doubles(int *numbers, size_t real_l);
void		print_error(void);
void		stack_u(t_StackI *istack, t_Stack *cur, t_Stack *prev, size_t size);
void		create_stack(int *nums, size_t size, t_StackI *istack);
int			check_ps(t_StackI *istack);
t_StackI	*init_stack(char name);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		select_action(t_StackI *a, t_StackI *b, char *line);
int			check_sort(t_StackI *istack);
void		free_stack(t_StackI *stack);

#endif