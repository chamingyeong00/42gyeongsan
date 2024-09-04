/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:00:12 by micha             #+#    #+#             */
/*   Updated: 2024/08/25 14:29:10 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	if ((nb == 0 && power != 0) || power < 0)
		return (0);
	if ((power == 0) || ((nb < 0) && (power == 0)))
		return (1);
	else
	{
		while (power > 0)
		{
			res = res * nb;
			power--;
		}
	}
	return (res);
}
