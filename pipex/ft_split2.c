/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:52:05 by yeham             #+#    #+#             */
/*   Updated: 2022/12/23 15:38:00 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	wordlen2(char const *s, char c)
{
	int	j;

	j = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && (*s != c))
		{
			while (*s && (*s != c))
				s++;
			j++;
		}
	}
	return (j);
}

char	cpy2(char **sp, char const *start, char const *s, int j)
{
	int	len;
	int	k;

	k = 0;
	len = s - start;
	sp[j] = (char *)malloc(sizeof(char) * (len + 2));
	if (sp[j] == NULL)
	{
		while (--j)
			free(sp[j]);
		free(sp);
		return (0);
	}
	while (k < len)
	{
		sp[j][k] = start[k];
		k++;
	}
	sp[j][k] = '/';
	sp[j][k + 1] = 0;
	return (1);
}

char	**nom2(char **sp, char const *s, char c)
{
	char const	*start;
	int			j;

	j = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		start = s;
		if (*s && (*s != c))
		{
			while (*s && (*s != c))
				s++;
			if (cpy2(sp, start, s, j) == 0)
				return (0);
			j++;
		}
	}
	sp[j] = 0;
	return (sp);
}

char	**ft_split2(char const *s, char c)
{
	char		**sp;

	if (s == 0)
		return (0);
	sp = (char **)malloc(sizeof(char *) * (wordlen2(s, c) + 1));
	if (sp == NULL)
		return (0);
	return (nom2(sp, s, c));
}

void	just_error(char *s)
{
	perror(s);
	exit(1);
}
