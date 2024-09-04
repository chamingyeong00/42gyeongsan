/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:37:57 by micha             #+#    #+#             */
/*   Updated: 2024/08/18 16:04:53 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'm')
			ft_putchar(str[i] + 13);
		else if (str[i] >= 'A' && str[i] <= 'M')
			ft_putchar(str[i] + 13);
		else if (str[i] >= 'n' && str[i] <= 'z')
			ft_putchar(str[i] - 13);
		else if (str[i] >= 'N' && str[i] <= 'Z')
			ft_putchar(str[i] - 13);
		else
			ft_putchar(str[i]);
		i++;
	}
		
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		rot_13(argv[1]);
	}
	ft_putchar('\n');
}
