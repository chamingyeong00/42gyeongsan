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

int ft_putnbr(long long int num)
{
	long long int	len;
	long long int	divisor;
	long long int 	n;

	divisor = 1;
	len = 0;
	if (num < 0){
		len += 1;
		ft_putchar('-');
	}
	n = num;
	while (n >= 10){
		divisor *= 10;
		n = n/10;
	}
	n = num;
	while (divisor > 0){
		ft_putchar((n / divisor) + '0');
		len += 1;
		n %= divisor;
		divisor /= 10;
	}
	return (len);
}