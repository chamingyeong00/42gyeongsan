/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:11:38 by micha             #+#    #+#             */
/*   Updated: 2025/02/16 09:11:42 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp;

	if (stack_from == NULL || *stack_from == NULL)
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (stack_to == NULL)
	{
		tmp->next = NULL;
		*stack_to = tmp;
	}
	else
	{
		tmp->next = *stack_to;
		*stack_to = tmp;
	}
}

void	push_a(t_stack **a_stack, t_stack **b_stack)
{
	push(b_stack, a_stack);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **a_stack, t_stack **b_stack)
{
	push(a_stack, b_stack);
	write(1, "pb\n", 3);
}
