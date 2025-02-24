/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:13:01 by micha             #+#    #+#             */
/*   Updated: 2025/02/16 09:13:03 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_numbers(char **argv_res, long *seen_numbers)
{
	int		j;
	long	num;

	j = 0;
	while (argv_res[j])
	{
		num = ft_atoi(argv_res[j]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		if (!is_valid(argv_res[j]))
			return (1);
		if (is_duplicate(seen_numbers, j, num))
			return (1);
		seen_numbers[j] = num;
		j++;
	}
	return (0);
}


int	is_check_error(int argc, char **argv, int cnt)
{
	int		i;
	char	**argv_res;
	long	*seen_numbers;

	i = 1;
	seen_numbers = (long *)malloc(sizeof(long) * ((size_t)cnt));
	if (!seen_numbers)
		return (1);
	ft_bzero(seen_numbers, sizeof(long) * (cnt));
	while (i < argc)
	{
		argv_res = ft_split(argv[i], ' ');
		if (!argv_res)
			return (free(seen_numbers), 1);
		if (handle_numbers(argv_res, seen_numbers))
		{
			free(seen_numbers);
			tmp_free(argv_res);
			return (1);
		}
		tmp_free(argv_res);
		i++;
	}
	free(seen_numbers);
	return (0);
}
