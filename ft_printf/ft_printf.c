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

int format_specifier_printf(const char *format, va_list ap){

	if (*format == 'c')
		return (ft_putchar((char)(va_arg(ap, int)))); //char와 같은 작은 자료형은 int로 확장되어 전달
	else if (*format == 's')
		return (ft_putstr((char *)(va_arg(ap, char *)))); //문자열 처리
	else if (*format == 'p'){
		char *c = "x";
		return (ft_puthex(c, (void *)(va_arg(ap, void *)))); //long long int X -> void * //포인턴 처리
	}
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr((int)(va_arg(ap, int)))); //long long int 사용 X -> unsigned int // 부호 있는 정수 처리
	else if (*format == 'u')
		return (ft_putnbr((unsigned int)(va_arg(ap, unsigned int))));
	else if (*format == 'x' || *format == 'X')
		return (ft_puthex(format, (unsigned int)(va_arg(ap, unsigned int)))); //int X -> unsinged int 16진수 처리
	else if (*format == '%'){
		ft_putchar('%');
		return 1;
	}else
		return 0;
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
