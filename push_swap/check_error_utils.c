/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:38:06 by micha             #+#    #+#             */
/*   Updated: 2025/02/16 15:38:07 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_resources(int *seen_cnt, long *seen_numbers)
{
	free(seen_numbers);
	free(seen_cnt);
	return (1);
}

void	tmp_free(char **tmp)
{
	int	idx;

	idx = 0;
	while (tmp[idx])
	{
		free(tmp[idx]);
		idx++;
	}
	free(tmp);
}

int	is_valid(char *argv_point)
{
	int		i;

	i = 0;
	if (argv_point[i] == '+' || argv_point[i] == '-')
		i++;
	while (argv_point[i])
	{
		if (!(argv_point[i] >= '0' && argv_point[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(long *arr, int cnt, long num)
{
	int		i;

	i = 0;
	while (i < cnt)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	worlds_count(char **s, char c)
{
	int	i;
	int	j;
	int	cnt;

	i = 1;
	j = 0;
	cnt = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] != c)
			{
				cnt++;
				while ((s[i][j] != c) && s[i][j] != '\0')
					j++;
			}
			else
				j++;
		}
		i++;
	}
	return (cnt);
}
