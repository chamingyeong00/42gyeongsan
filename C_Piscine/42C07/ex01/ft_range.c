/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:38:59 by micha             #+#    #+#             */
/*   Updated: 2024/08/27 21:26:51 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	range;
	int	*res;

	if (min >= max)
		return (0);
	range = max - min;
	res = (int *)malloc(range * sizeof(int));
	if (res == 0)
		return (0);
	i = 0;
	while (i < range)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
