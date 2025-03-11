/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:26:32 by micha             #+#    #+#             */
/*   Updated: 2025/01/10 00:26:33 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)ch)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)ch)
		return ((char *)&str[i]);
	return (0);
}

int	ft_strlen(const char *str)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		cnt++;
		i++;
	}
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*string;

	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	string = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!string)
		return (0);
	while (++i < s1_len)
		string[i] = s1[i];
	free((void *)s1);
	i = -1;
	while (++i < s2_len)
		string[s1_len + i] = s2[i];
	string[s1_len + i] = '\0';
	return (string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;
	unsigned int	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	substring = (char *)malloc(len * sizeof(char) + 1);
	if (!substring)
		return (0);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strdup(const char *src)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!temp)
		return (0);
	while (src[i] != '\0')
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
