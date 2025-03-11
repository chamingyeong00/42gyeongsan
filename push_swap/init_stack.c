/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:11:31 by micha             #+#    #+#             */
/*   Updated: 2025/02/16 09:11:33 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **head, int cnt)
{
	t_stack	*tmp;
	int		count;

	tmp = *head;
	count = 1;
	while (tmp && tmp->next)
	{
		if (tmp->index < tmp->next->index)
			count++;
		tmp = tmp->next;
	}
	if (cnt > count)
		return (0);
	return (1);
}

t_stack	*make_new_node(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->val = num;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	insert_stack(t_stack **a_stack, int num)
{
	t_stack	*new_node;
	t_stack	*current;

	if (*a_stack == NULL)
	{
		*a_stack = make_new_node(num);
	}
	else
	{
		current = *a_stack;
		while (current->next != NULL)
			current = current->next;
		new_node = make_new_node(num);
		current->next = new_node;
	}
	return ;
}

t_stack	*init_stack(int argc, char **argv)
{
	int		i;
	int		j;
	long	num;
	char	**argv_res;
	t_stack	*a_stack;

	i = 0;
	a_stack = NULL;
	if (argc > 1)
	{
		while (argv[++i])
		{
			j = -1;
			argv_res = ft_split(argv[i], ' ');
			if (!argv_res)
				stack_free(a_stack);
			while (argv_res[++j])
			{
				num = ft_atoi(argv_res[j]);
				insert_stack(&a_stack, num);
			}
			tmp_free(argv_res);
		}
	}
	return (a_stack);
}
