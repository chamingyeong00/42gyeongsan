/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:52:56 by micha             #+#    #+#             */
/*   Updated: 2024/12/22 12:52:57 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int n)
{
	unsigned int	len;
	unsigned int	divisor;
	unsigned int	num;

	divisor = 1;
	len = 0;
	num = n;
	if (num == 0)
		return (ft_putchar('0'));
	while (num >= 10)
	{
		divisor *= 10;
		num = num / 10;
	}
	while (divisor > 0)
	{
		ft_putchar((n / divisor) + '0');
		len += 1;
		n %= divisor;
		divisor /= 10;
	}
	return (len);
}

int	ft_putnbr(int num)
{
	int				len;
	unsigned int	divisor;
	unsigned int	n;

	divisor = 1;
	len = 0;
	if (num == 0)
		return (ft_putchar('0'));
	if (num < 0)
	{
		n = -num;
		len += ft_putchar('-');
	}
	else
		n = num;
	while (n / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		len += ft_putchar((n / divisor) + '0');
		n %= divisor;
		divisor /= 10;
	}
	return (len);
}
