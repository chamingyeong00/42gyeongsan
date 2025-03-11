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
#include <stdio.h>

int	handle_numbers(char **argv_res, long *seen_numbers, int *seen_cnt)
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
		if (is_duplicate(seen_numbers, *seen_cnt, num))
			return (1);
		seen_numbers[j] = num;
		(*seen_cnt)++;
		j++;
	}
	return (0);
}

int	*initialize_seen_cnt(void)
{
	int	*seen_cnt;

	seen_cnt = malloc(sizeof(int));
	if (!seen_cnt)
		return (NULL);
	*seen_cnt = 0;
	return (seen_cnt);
}

long	*initialize_seen_numbers(int cnt)
{
	long	*seen_numbers;

	seen_numbers = malloc(sizeof(long) * cnt);
	if (!seen_numbers)
		return (NULL);
	ft_bzero(seen_numbers, sizeof(long) * cnt);
	return (seen_numbers);
}

int	handle_error(char **argv_res, int *seen_cnt, long *seen_numbers)
{
	if (argv_res)
		tmp_free(argv_res);
	free_resources(seen_cnt, seen_numbers);
	return (1);
}

int	is_check_error(int argc, char **argv, int cnt)
{
	int		i;
	int		*seen_cnt;
	long	*seen_numbers;
	char	**argv_res;

	i = 1;
	seen_cnt = initialize_seen_cnt();
	if (!seen_cnt)
		return (free(seen_cnt), 1);
	seen_numbers = initialize_seen_numbers(cnt);
	if (!seen_numbers)
		return (free(seen_cnt), free(seen_numbers), 1);
	while (i < argc)
	{
		argv_res = ft_split(argv[i], ' ');
		if (!argv_res || handle_numbers(argv_res, seen_numbers, seen_cnt))
			return (handle_error(argv_res, seen_cnt, seen_numbers));
		tmp_free(argv_res);
		i++;
	}
	free_resources(seen_cnt, seen_numbers);
	return (0);
}
