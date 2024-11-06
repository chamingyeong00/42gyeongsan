/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 00:53:14 by chsung            #+#    #+#             */
/*   Updated: 2024/08/28 15:35:24 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**allocate_dp_array(t_map *map)
{
	int	i;
	int	j;
	int	**dp;

	i = -1;
	dp = (int **)malloc(map->height * sizeof(int *));
	while (++i < map->height)
	{
		j = -1;
		dp[i] = (int *)malloc(map->width * sizeof(int));
		while (++j < map->width)
		{
			if (i == 0 || j == 0)
			{
				if (map->map[i][j] == map->empty)
					dp[i][j] = 1;
				else
					dp[i][j] = 0;
			}
			else
				dp[i][j] = -1;
		}
	}
	return (dp);
}

void	free_dp_array(int **dp, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

void	compute_max_sqaure(int **dp, t_map *map, t_max *max_point)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (dp[i][j] == -1)
			{
				if (map->map[i][j] == map->obstacle)
					dp[i][j] = 0;
				else
					dp[i][j] = min(dp[i - 1][j - 1], \
									dp[i - 1][j], dp[i][j - 1]) + 1;
			}
			if (dp[i][j] > max_point->size)
			{
				max_point->size = dp[i][j];
				max_point->i = i;
				max_point->j = j;
			}
		}
	}
}

void	fill_max_square(t_map *map, t_max *max_point)
{
	int		cur_i;
	int		cur_j;
	char	full;

	cur_i = max_point->i - max_point->size;
	full = map->full;
	while (++cur_i <= max_point->i)
	{
		cur_j = max_point->j - max_point->size;
		while (++cur_j <= max_point->j)
			map->map[cur_i][cur_j] = full;
	}
}

void	bsq_solve(t_map *map)
{
	int		**dp;
	t_max	max_point;

	max_point.size = 0;
	max_point.i = 0;
	max_point.j = 0;
	dp = allocate_dp_array(map);
	compute_max_sqaure(dp, map, &max_point);
	fill_max_square(map, &max_point);
	free_dp_array(dp, map->height);
	bsq_print_map(map);
}
