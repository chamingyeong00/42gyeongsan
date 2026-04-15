/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:20:27 by micha             #+#    #+#             */
/*   Updated: 2024/10/12 14:20:29 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	is_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

char	*str_dup(char *str, char c)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	len = 0;
	while (str[len] != '\0' && !is_sep(str[len], c))
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	world_count(char *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (!is_sep(s[i], c))
		{
			cnt++;
			while (!is_sep(s[i], c) && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

char	**fill_result(char *s, char c, char **result, int k)
{
	int		i;

	i = 0;
	while (*s != '\0')
	{
		if (!is_sep(*s, c))
		{
			result[i++] = str_dup(s, c);
			if (!result[i - 1])
			{
				k = 0;
				while (k < i)
				{
					free(result[k++]);
				}
				return (0);
			}
			while (!is_sep (*s, c) && *s != '\0')
				s++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char *s, char c)
{
	int		len;
	int		k;
	char	**result;

	k = 0;
	len = world_count(s, c);
	result = (char **)malloc((len + 1) * sizeof(char *));
	if (result == 0)
		return (0);
	result = fill_result(s, c, result, k);
	return (result);
}
