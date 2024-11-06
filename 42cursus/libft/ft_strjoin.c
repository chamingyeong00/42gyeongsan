/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:18:17 by micha             #+#    #+#             */
/*   Updated: 2024/10/09 16:18:18 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;
	char	*string;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	string = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!string)
		return (0);
	while (i < s1_len)
	{
		string[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		string[s1_len + j] = s2[j];
		j++;
	}
	string[s1_len + j] = '\0';
	return (string);
}
