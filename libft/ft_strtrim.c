/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:29:44 by micha             #+#    #+#             */
/*   Updated: 2024/10/09 16:29:45 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

int	is_set(char const *set, char c)
{
	int		i;
	int		set_len;

	i = 0;
	set_len = ft_strlen(set);
	while (i < set_len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	idx_set(char const *s, char const *set, int start)
{
	int		i;
	size_t	s_len;

	i = start;
	s_len = ft_strlen(s);
	if (i == 0)
	{
		while (i < (int)s_len && is_set(set, s[i]))
		{
			i++;
		}
	}
	else
	{
		while (i >= 0 && is_set(set, s[i]))
		{
			i--;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	int			start_idx;
	int			end_idx;
	char		*string;

	i = -1;
	if (!s1 || !set)
		return (0);
	start_idx = idx_set(s1, set, 0);
	end_idx = idx_set(s1, set, ft_strlen(s1) - 1);
	if (start_idx > end_idx)
	{
		string = (char *)malloc(1 * sizeof(char));
		if (!string)
			return (0);
		string[0] = '\0';
		return (string);
	}
	string = (char *)malloc((end_idx - start_idx + 2) * sizeof(char));
	if (!string)
		return (0);
	while (start_idx + (int)++i <= end_idx)
		string[i] = s1[start_idx + i];
	string[i] = '\0';
	return (string);
}
