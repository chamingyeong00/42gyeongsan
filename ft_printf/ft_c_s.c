/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:52:48 by micha             #+#    #+#             */
/*   Updated: 2024/12/22 12:52:51 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
	{//(*s)X 이유
		write(1, "(null)", 6);
		//ft_putstr("(null)"); //NULL 역참조하면 메모리 접근 오류 발생
		return (6); //return (ft_putchar("null"));
	}
	while (*s)
	{//\0(문자열의 끝을 나타내는 ASCII 0 RKQT) != NULL(포인터가 가리키는 값이 없음) (*s)!=NULL은 NULL과 \0을 혼동할 가능성있음
		ft_putchar(*s);
		s++;
		len++;
	}
	return (len);
}