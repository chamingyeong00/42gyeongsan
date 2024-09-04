/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:06:44 by micha             #+#    #+#             */
/*   Updated: 2024/08/25 23:18:44 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*range;
	int	i;

	if (start > end)
		range = (int *)malloc(sizeof(int) * (start - end + 1));
	else
		range = (int *)malloc(sizeof(int) * (end - start + 1));
	if (!range)
		return 0;
	i = 0;
	if (start <= end)
	{
		while (start <= end)
		{
			range[i] = start;
			start ++;
			i++;
		}
	else
	{
		while (start >= end)
		{
			range[i] = end;
			i++;
			end ++;
		}
	}
	return (range);
}	
