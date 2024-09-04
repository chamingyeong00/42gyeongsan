/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:35:25 by micha             #+#    #+#             */
/*   Updated: 2024/08/30 10:32:59 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

char	*str_dup(char *str, char *charset)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	len = 0;
	while (str[len] != '\0' && !is_sep(str[len], charset))
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	element_count(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset))
		{
			cnt++;
			while (!is_sep(str[i], charset) && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		len;
	char	**result;

	i = 0;
	len = element_count(str, charset);
	result = (char **)malloc((len + 1) * sizeof(char *));
	if (result == 0)
		return (0);
	while (*str != '\0')
	{
		if (!is_sep(*str, charset))
		{
			result[i++] = str_dup(str, charset);
			while (!is_sep (*str, charset) && *str != '\0')
				str++;
		}
		else
			str++;
	}
	result[i] = 0;
	return (result);
}
