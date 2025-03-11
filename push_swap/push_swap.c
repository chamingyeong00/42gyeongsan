/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:11:24 by micha             #+#    #+#             */
/*   Updated: 2025/02/16 09:11:50 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	stack_free(t_stack *st)
{
	t_stack	*tmp;

	while (st)
	{
		tmp = st->next;
		free(st);
		st = tmp;
	}
}

int	ft_error(void)
{
	char	*s;

	s = "Error\n";
	write(2, s, 6);
	return (0);
}

int	main(int argc, char **argv)
{
	int		cnt;
	t_stack	*a_stack;
	t_stack	*b_stack;

	cnt = 0;
	if (argc == 1)
		return (ft_error());
	cnt = worlds_count(argv, ' ');
	if (is_check_error(argc, argv, cnt))
		return (ft_error());
	a_stack = init_stack(argc, argv);
	b_stack = NULL;
	set_index(a_stack, cnt);
	if (is_sorted(&a_stack, cnt))
		return (stack_free(a_stack), 0);
	if (cnt <= 3)
		small_radix_sort(&a_stack);
	else if (cnt <= 5)
		middle_radix_sort(&a_stack, &b_stack, cnt);
	else
		big_radix_sort(&a_stack, &b_stack);
	stack_free(a_stack);
	stack_free(b_stack);
	return (0);
}
