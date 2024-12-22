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

int ft_puthex(const char *format, void *num)
{
	char			*base_digits1;
	char			*base_digits2;
	char			converted_number[64];
	int				index;
	int				len;
	unsigned long	n;

	n = (unsigned long)num;
	base_digits1 = "0123456789abcdef";
	base_digits2 = "0123456789ABCDEF";
	index = 0;
	
	while(n != 0){
		converted_number[index++] = n % 16;
		n = n / 16;
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