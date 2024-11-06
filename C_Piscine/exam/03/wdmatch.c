/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:37:42 by micha             #+#    #+#             */
/*   Updated: 2024/08/25 21:49:09 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	wdmath(char *s1, char *s2)
{
	int	i;
	int	j;
	int	len;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (s1[i])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				count++;
				break;
			}
			j++;
		}
		i++;
	}
	if (count == len)
		ft_putstr(s1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
		wdmath(argv[1], argv[2]);
	write(1, "\n", 1);
}
