/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:52:15 by micha             #+#    #+#             */
/*   Updated: 2024/08/27 23:48:46 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	sep_len;
	int	total;

	i = 0;
	total = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	if (size > 1)
		total += (size - 1) * sep_len;
	return (total);
}

char	*ft_strcat(int size, char **strs, char *sep, char *res)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while (strs[i][j] != '\0')
			res[k++] = strs[i][j++];
		j = 0;
		if (i < size - 1)
		{
			while (sep[j] != '\0')
				res[k++] = sep[j++];
		}
		j = 0;
		i++;
	}
	res[k] = '\0';
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		len;

	if (size <= 0)
	{
		res = (char *)malloc(sizeof(char));
		if (res)
			res[0] = '\0';
		return (res);
	}
	len = ft_total_len(size, strs, sep);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	return (ft_strcat(size, strs, sep, res));
}
