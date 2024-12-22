/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 10:56:22 by micha             #+#    #+#             */
/*   Updated: 2024/12/22 10:56:24 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTH_H
# define  FT_PRINT_H
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int 	ft_numlen(int num);
int		ft_puthex(const char *format, long long int num);
int		ft_putnbr(long long int num);
int 	format_specifier_printf(const char *format, va_list ap);
int		ft_printf(const char *format, ...);

#endif