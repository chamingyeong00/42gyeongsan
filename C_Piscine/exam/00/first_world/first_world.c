/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:05:41 by micha             #+#    #+#             */
/*   Updated: 2024/08/18 14:12:50 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	first_world(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '	')
	{
		i++;
	}
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '	')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		first_world(argv[1]);
	else
		ft_putchar('\n');
}
