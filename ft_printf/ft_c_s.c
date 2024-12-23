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
	if (!s){//(*s)X 이유
		write(1, "(null)", 6);
		//ft_putstr("(null)"); //NULL 역참조하면 메모리 접근 오류 발생
		return (6); //return (ft_putchar("null"));
	}	
	len = 0;
	while ((*s) != NULL){
		ft_putchar(*s);
		s++;
		len++;
	}
	return (len);
}