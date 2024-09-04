/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:57:16 by chsung            #+#    #+#             */
/*   Updated: 2024/08/14 16:35:06 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	print_row(int r, char first, char mid, char last);

void	rush(int x, int y)
{
	int		i;
	char	first;
	char	mid;
	char	last;

	i = 0;
	while (i < y)
	{
		if (i == 0 || i == y - 1)
		{
			first = 'A';
			mid = 'B';
			last = 'C';
		}
		else
		{
			first = 'B';
			mid = ' ';
			last = 'B';
		}
		print_row(x, first, mid, last);
		i++;
	}
}

void	print_row(int r, char first, char mid, char last)
{
	int	i;

	i = 0;
	while (i < r)
	{
		if (i == 0)
			ft_putchar(first);
		else if (i == r - 1)
			ft_putchar(last);
		else
			ft_putchar(mid);
		i++;
	}
	if (i != 0)
		ft_putchar('\n');
}
