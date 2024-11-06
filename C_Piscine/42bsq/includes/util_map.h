/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:23:52 by chsung            #+#    #+#             */
/*   Updated: 2024/08/26 23:23:53 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_MAP_H
# define UTIL_MAP_H

# include <unistd.h>
# include <stdlib.h>
# include "struct.h"

int		bsq_is_prinatable(char c);
int		bsq_is_valid_info(t_map *map);
void	bsq_map_free(t_map *map, int height);
void	bsq_print_map(const t_map *map);

#endif
