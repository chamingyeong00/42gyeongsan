/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:34:05 by micha             #+#    #+#             */
/*   Updated: 2024/08/19 09:51:45 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	res;

	res = 0;
	if (len == 0)
		return (0);
	len--;
	res = tab[len];
	while (len > 0)
	{
		if (tab[len] > res)
			res = tab[len];
		len--;
	}
	return (res);
}

int	main(void)
{
	int	tab[4] = {5, 3, 1, 7};
	unsigned int	len;

	len = 4;
	printf("%d", max(tab, len));
}
