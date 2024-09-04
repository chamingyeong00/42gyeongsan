/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:59:48 by chsung            #+#    #+#             */
/*   Updated: 2024/08/28 16:59:50 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	bsq_invalid_info(t_str *line, t_map *map)
{
	int	i;

	if (line->last < 3)
		return (1);
	map->height = 0;
	map->empty = line->str[line->last - 2];
	map->obstacle = line->str[line->last - 1];
	map->full = line->str[line->last];
	i = -1;
	while (++i < line->last - 2)
	{
		if (!('0' <= line->str[i] && line->str[i] <= '9'))
			return (1);
		map->height *= 10;
		map->height += line->str[i] - '0';
	}
	bsq_str_free(line);
	if (bsq_is_valid_info(map))
		return (1);
	return (0);
}

int	bsq_check_map_line(t_map *map, int i, t_str *line)
{
	int	j;

	map->map[i] = (char *)malloc((line->last + 1) * sizeof(char));
	j = -1;
	while (++j <= line->last)
	{
		if (line->str[j] != map->empty && line->str[j] != map->obstacle)
		{
			bsq_map_free(map, i + 1);
			return (0);
		}
		if (map->empty_seen == 0 && line->str[j] == map->empty)
			map->empty_seen = 1;
		map->map[i][j] = line->str[j];
	}
	return (1);
}

int	bsq_read_map_file_line(int fd, t_map *map, int i)
{
	t_str	*line;

	line = bsq_read_line(fd);
	if (line->last == -1)
	{
		bsq_str_free(line);
		bsq_map_free(map, i);
		return (0);
	}
	if (i == 0)
		map->width = line->last + 1;
	if (line->last + 1 != map->width || line->meet_nl != 1)
	{
		bsq_str_free(line);
		bsq_map_free(map, i);
		return (0);
	}
	if (!bsq_check_map_line(map, i, line))
	{
		bsq_str_free(line);
		return (0);
	}
	bsq_str_free(line);
	return (1);
}

int	bsq_read_map_file(int fd, t_map *map)
{
	int		i;
	char	c;

	i = -1;
	while (++i < map->height)
	{
		if (!bsq_read_map_file_line(fd, map, i))
			return (0);
	}
	if (read(fd, &c, 1) != 0)
	{
		bsq_map_free(map, map->height);
		return (0);
	}
	if (map->empty_seen != 1)
	{
		bsq_map_free(map, map->height);
		return (0);
	}
	return (1);
}

t_map	*bsq_build_map(int fd)
{
	t_str	*line;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->empty_seen = 0;
	if (!map)
		return (NULL);
	line = bsq_read_line(fd);
	if (bsq_invalid_info(line, map))
	{
		free(map);
		return (NULL);
	}
	map->map = (char **)malloc(map->height * sizeof(char *));
	if (bsq_read_map_file(fd, map))
		return (map);
	return (NULL);
}
