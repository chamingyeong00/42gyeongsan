/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:53:13 by micha             #+#    #+#             */
/*   Updated: 2024/12/22 12:53:15 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(const char *format, unsigned long long num)
{
	char			*base_digits1;
	char			*base_digits2;
	char			converted_number[64];
	int				index;
	unsigned long long				len;

	base_digits1 = "0123456789abcdef";
	base_digits2 = "0123456789ABCDEF";
	index = 0;
	if (num == 0)
		return(ft_putchar('0'));
	while(num != 0){
		converted_number[index++] = num % 16;
		num = num / 16;
	}
	len = index;
	if (*format == 'x'){
		while(--index >= 0)
			ft_putchar(base_digits1[converted_number[index]]);
	}else{
		while(--index >= 0)
			ft_putchar(base_digits2[converted_number[index]]);
	}
	return (len);
}