/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:45:05 by micha             #+#    #+#             */
/*   Updated: 2024/08/28 00:39:55 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_str_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*d;

	i = 0;
	d = ((char *)malloc(ft_str_length(str) * sizeof(char) + 1));
	if (!d)
		return (0);
	while (str[i])
	{
		d[i] = str[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*d;

	d = (malloc((ac + 1) * sizeof(struct s_stock_str)));
	if (!d)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		d[i].size = ft_str_length(av[i]);
		d[i].str = av[i];
		d[i].copy = ft_strdup(av[i]);
		i++;
	}
	d[i].str = 0;
	d[i].copy = 0;
	return (d);
}
