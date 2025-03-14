/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:33:41 by micha             #+#    #+#             */
/*   Updated: 2024/10/12 14:33:50 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_len(unsigned int num)
{
	int		cnt;

	cnt = 0;
	if (num == 0)
		cnt++;
	while (num > 0)
	{
		num = num / 10;
		(cnt)++;
	}
	return (cnt);
}

void	check_mark(char *res, int *len, int *i, int n)
{
	if (n < 0)
	{
		res[0] = '-';
		(*len)++;
		*i = *len;
	}
	else
	{
		(*i) = *len;
	}
}

char	*allocate(int n, int len)
{
	char	*res;

	if (n < 0)
		res = (char *)malloc(len * sizeof(char) + 2);
	else
		res = (char *)malloc(len * sizeof(char) + 1);
	return (res);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*res;
	int				i;
	unsigned int	num;

	if (n < 0)
		num = -n;
	else
		num = n;
	len = ft_len(num);
	res = allocate(n, len);
	if (!res)
		return (0);
	check_mark(res, &len, &i, n);
	if (res == 0)
		return (0);
	res[i--] = '\0';
	while (i >= 0 && res[i] != '-')
	{
		res[i] = ((num % 10) + '0');
		i--;
		num = num / 10;
	}
	return (res);
}
