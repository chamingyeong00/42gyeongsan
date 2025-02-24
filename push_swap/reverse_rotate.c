/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:12:01 by micha             #+#    #+#             */
/*   Updated: 2025/02/16 09:12:03 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **head)
{
	t_stack	*prev_tail;
	t_stack	*new_tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	prev_tail = *head;
	while (prev_tail->next != NULL)
	{
		new_tail = prev_tail;
		prev_tail = prev_tail->next;
	}
	prev_tail->next = *head;
	new_tail->next = NULL;
	*head = prev_tail;
}

void	reverse_rotate_a(t_stack **head)
{
	reverse_rotate(head);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **head)
{
	reverse_rotate(head);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_stack **a_stack, t_stack **b_stack)
{
	reverse_rotate(a_stack);
	reverse_rotate(b_stack);
	write(1, "rrr\n", 4);
}
