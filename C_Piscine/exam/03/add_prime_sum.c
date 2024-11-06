/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:59:57 by micha             #+#    #+#             */
/*   Updated: 2024/08/25 15:28:29 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_prime(int num)
{
	int	i;

	i = 2;
	if (num < 2)
		return (0);
	while (i * i <= num)
	{
		if ((num % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	sum;
	int	i;
	int	num;

	if (argc != 2)
		return (1);
	i = 2;
	sum = 0;

	num = ft_atoi(argv[1]);
	while (i <= num)
	{
		if (is_prime(i))
		{
			sum += i;
		}
		i++;
	}

	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}
