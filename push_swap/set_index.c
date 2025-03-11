/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:12:16 by micha             #+#    #+#             */
/*   Updated: 2025/02/16 09:12:18 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *bottom, int cnt)
{
	t_stack	*big;
	t_stack	*temp;

	while (cnt-- > 0)
	{
		big = NULL;
		temp = bottom;
		while (temp)
		{
			if (!temp->index && (big == NULL || temp->val > big->val))
				big = temp;
			temp = temp->next;
		}
		if (big != NULL)
			big->index = cnt;
	}
}
