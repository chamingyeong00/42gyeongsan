/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:27:47 by chsung            #+#    #+#             */
/*   Updated: 2024/08/26 22:27:48 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "bsq.h"
#include "map.h"

void	solve(char *file)
{
	int		fd;
	t_map	*map;

	if (file != NULL)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			bsq_print_error();
			return ;
		}
	}
	else
		fd = 0;
	map = bsq_build_map(fd);
	if (map == NULL)
	{
		bsq_print_error();
		return ;
	}
	bsq_solve(map);
	bsq_map_free(map, map->height);
	close(fd);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = -1;
	if (argc == 1)
		solve(NULL);
	else
	{
		i = 0;
		while (++i < argc)
			solve(argv[i]);
	}
	return (0);
}
