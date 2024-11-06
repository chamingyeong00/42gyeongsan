/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:19:47 by micha             #+#    #+#             */
/*   Updated: 2024/08/19 08:46:15 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	last_word(char *str)
{
	int	i;n
	int	j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && (str[i +1] >= 33 && str[i + 1] <= 126)) //33부터
			j = i + 1;
		i++;
	}
	while (str[j] >= 33 && str[j] <= 126) //
	{
		ft_putchar(str[j]);
		j++;
	}
}
 
int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	ft_putchar('\n');
}
