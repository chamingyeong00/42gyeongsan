/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:23:46 by chsung            #+#    #+#             */
/*   Updated: 2024/08/26 23:23:47 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_map.h"

int	bsq_is_prinatable(char c)
{
	return (32 <= c && c <= 126);
}

int	bsq_is_valid_info(t_map *map)
{
	return (
		map->height <= 0 || \
		!bsq_is_prinatable(map->empty) || \
		!bsq_is_prinatable(map->obstacle) || \
		!bsq_is_prinatable(map->full) || \
		map->empty == map->obstacle || \
		map->empty == map->full || \
		map->obstacle == map->full
	);
}

void	bsq_map_free(t_map *map, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(map->map[i]);
	free(map->map);
	free(map);
}

void	bsq_print_map(const t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			write(1, &map->map[row][col], 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
