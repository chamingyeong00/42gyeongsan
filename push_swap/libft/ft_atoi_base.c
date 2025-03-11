/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:21:38 by micha             #+#    #+#             */
/*   Updated: 2024/08/24 15:54:17 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	len;
	int	i;
	int	j;

	len = str_len(base);
	i = 0;
	if (len <= 1 || base[i] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if ((base[i] == ' ') || (base[i] >= 9 && base[i] <= 13))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	str_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_mark(char *str, int *i)
{	
	int	mark;

	mark = 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			mark = -mark;
		(*i)++;
	}
	return (mark);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	mark;
	int	index;
	int	i;
	int	len;

	len = str_len(base);
	res = 0;
	i = 0;
	if (!check_base(base))
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	mark = check_mark(str, &i);
	while (str[i])
	{
		index = str_index(str[i], base);
		if (index == -1)
			break ;
		res = res * len + index;
		i++;
	}
	return (mark * res);
}
