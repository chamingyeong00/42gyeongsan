/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:51:08 by micha             #+#    #+#             */
/*   Updated: 2024/08/25 23:06:36 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_size(int start, int end)
{
	int	size;

	size = end - start;
	if (size < 0)
		size = -size;
	return (size + 1);
}

int	*ft_range(int start, int end)
{
	int	size;
	int	*res;
	int	i;

	size = ft_size(start, end);
	res = (int *)malloc(size * sizeof(int));
	i = 0;
	if (res)
		return (0);
	if (size == 1)
		res[0] = start;
	if (start < end)
	{
		while (i < size)
		{
			res[i] = start + i;
			i++;
		}
	}
	if (start > end)
	{
		while (i < size)
		{
			res[i] = end + i;
			i--;
		}
	}
	return (res);
}

int	main(void)
{
	int	size;
	int	i;
	int	*res;
	int	start;
	int	end;

	start = 0;
	end = 3;
	size = ft_size(start, end);
	res = ft_range(start, end);
	i = 0;
	while (i < size)
	{
		printf("%d", res[i]);
		i++;
	}
}
