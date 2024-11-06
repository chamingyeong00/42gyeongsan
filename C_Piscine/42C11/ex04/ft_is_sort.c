/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:08:15 by micha             #+#    #+#             */
/*   Updated: 2024/09/01 10:56:08 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	increasing;
	int	decreasing;

	i = 0;
	increasing = 1;
	decreasing = 1;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			decreasing = 0;
		if ((*f)(tab[i], tab[i + 1]) > 0)
			increasing = 0;
		i++;
	}
	if (increasing == 1 || decreasing == 1)
		return (1);
	else
		return (0);
}
