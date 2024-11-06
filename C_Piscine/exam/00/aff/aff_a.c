/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:44:31 by micha             #+#    #+#             */
/*   Updated: 2024/08/18 13:43:48 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	aff_a(char *str)//
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == 'a')
			ft_putchar('a');
		i++;
	}
	ft_putchar('\n');//
	return (*str);//
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		aff_a(argv[1]);
	else
	{
		ft_putchar('\n');//
	}
	return (0);//
}

