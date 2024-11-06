/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:42:37 by chsung            #+#    #+#             */
/*   Updated: 2024/08/26 22:42:38 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_str
{
	char	*str;
	int		size;
	int		last;
	int		meet_nl;
}	t_str;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		empty_seen;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

typedef struct s_max
{
	int	i;
	int	j;
	int	size;
}	t_max;

#endif
