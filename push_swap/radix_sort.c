/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:11:55 by micha             #+#    #+#             */
/*   Updated: 2025/02/16 09:11:57 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_big_index(t_stack *head)
{
	int		big;
	t_stack	*temp;

	big = -2147483648;
	temp = head;
	while (temp)
	{
		if (temp->index > big)
			big = temp->index;
		temp = temp->next;
	}
	return (big);
}

int	find_bit(int big_nbr)
{
	int	big_bit;

	big_bit = 0;
	while (big_nbr > 0)
	{
		big_nbr >>= 1;
		big_bit++;
	}
	return (big_bit);
}

void	small_radix_sort(t_stack **head)
{
	int	big_index;

	big_index = find_big_index(*head);
	if ((*head)->index == big_index)
		rotate_a(head);
	else if ((*head)->next->index == big_index)
		reverse_rotate_a(head);
	if ((*head)->index > (*head)->next->index)
		swap_a(head);
}

void	middle_radix_sort(t_stack **a_stack, t_stack **b_stack, int cnt)
{
	while (cnt--)
	{
		if ((*a_stack)->index == 0 || (*a_stack)->index == 1)
			push_b(a_stack, b_stack);
		else
			rotate_a(a_stack);
	}
	small_radix_sort(a_stack);
	push_a(a_stack, b_stack);
	push_a(a_stack, b_stack);
	if ((*a_stack)->index > (*a_stack)->next->index)
		swap_a(a_stack);
}

void	big_radix_sort(t_stack **a_stack, t_stack **b_stack)
{
	int	big_index;
	int	max_bit;
	int	i;
	int	j;

	big_index = find_big_index(*a_stack);
	max_bit = find_bit(big_index);
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j <= big_index)
		{
			if (((*a_stack)->index >> i) & 1)
				rotate_a (a_stack);
			else
				push_b(a_stack, b_stack);
			j++;
		}
		while (*b_stack)
			push_a(a_stack, b_stack);
		i++;
	}
}
