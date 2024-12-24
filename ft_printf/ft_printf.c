/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:50:46 by micha             #+#    #+#             */
/*   Updated: 2024/11/06 22:50:49 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int format_specifier_printf(const char *format, va_list ap){

	if (*format == 'c')
		return (ft_putchar((char)(va_arg(ap, int)))); //char와 같은 작은 자료형은 int로 확장되어 전달
	else if (*format == 's'){
		return (ft_putstr((va_arg(ap, char *)))); //문자열 처리
	}
	else if (*format == 'p'){ //p는 0x 접두사를 포함한 소문자 16진수 출력
		unsigned long long *ptr = va_arg(ap, unsigned long long);
		if (ptr == 0)
			return(ft_putstr("(nil)"));
		ft_putstr("0x");
		return (2 +  ft_long_puthex(ptr));
	}
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr((va_arg(ap, int)))); //int 부호 있는 정수 처리
	else if (*format == 'u')
		return (ft_unsigned_putnbr((va_arg(ap, unsigned int)))); //u : unsigned int llu : unsigned long long
	else if (*format == 'x' || *format == 'X')
		return (ft_puthex(format, (va_arg(ap, unsigned int)))); //int X -> unsinged int 16진수 처리
	else if (*format == '%')
		return (ft_putchar('%'));
	else {//포멧 검증 실패시
		ft_putchar('%');
		return (ft_putchar(*format) + 1);
	}
} 

int	ft_printf(const char *format, ...)
{
	va_list	ap;
    int		len;

    len = 0;
    va_start(ap, format);
    while(*format){
       if(*format != '%'){
            len += write(1, format, 1);
       }
       else{
			format++;
			len += format_specifier_printf(format, ap);
       }
	   format++;
    }
    va_end(ap);
	return len;
}
