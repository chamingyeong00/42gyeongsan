/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:14:40 by micha             #+#    #+#             */
/*   Updated: 2024/08/24 18:11:50 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}	

int	check_base(char *base)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	len = str_len(base);
	if (len <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	n;

	n = nbr;
	i = 0;
	len = str_len(base);
	if (check_base(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		if (n / len > 0)
		{
			ft_putnbr_base(n / len, base);
			ft_putnbr_base(n % len, base);
		}
		else
		{
			write(1, &base[n], 1);
		}
	}
}

int	main(void)
{
	ft_putnbr_base(2147483647, "0123456789");
}
