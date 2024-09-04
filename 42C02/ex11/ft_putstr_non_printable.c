/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:12:03 by micha             #+#    #+#             */
/*   Updated: 2024/08/17 15:33:35 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_unprintable(char c)
{
	return (!(c > 31 && c < 127));
}

void	to_hex(unsigned char c)
{
	int		div;
	int		mod;

	div = c / 16;
	if (div < 10)
		ft_putchar(div + '0');
	else
		ft_putchar((div - 10) + 'a');
	mod = c % 16;
	if (mod < 10)
		ft_putchar(mod + '0');
	else
		ft_putchar('a' + (mod - 10));
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_unprintable(str[i]))
		{
			write(1, "\\", 1);
			to_hex((unsigned char)str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
