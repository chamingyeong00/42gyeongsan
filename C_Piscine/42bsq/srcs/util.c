/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:59:59 by chsung            #+#    #+#             */
/*   Updated: 2024/08/28 17:00:01 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	bsq_print_error(void)
{
	write(2, "map error\n", 10);
}

int	min(int a, int b, int c)
{
	int	res;

	res = a;
	if (b < res)
		res = b;
	if (c < res)
		res = c;
	return (res);
}
