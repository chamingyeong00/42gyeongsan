/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:30:59 by micha             #+#    #+#             */
/*   Updated: 2024/08/24 15:52:14 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	value;
	int	mark;
	int	mark_count;

	value = 0;
	mark = 1;
	mark_count = 0;
	i = is_space(str);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mark_count++;
		i++;
	}
	if (mark_count % 2 == 1)
		mark = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	value = value * mark;
	return (value);
}
