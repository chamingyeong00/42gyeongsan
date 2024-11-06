/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:13:36 by micha             #+#    #+#             */
/*   Updated: 2024/10/01 21:13:37 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	find_len;

	i = 0;
	find_len = ft_strlen(find);
	if (*find == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		if (len < find_len + i)
			break ;
		if (ft_strncmp(&str[i], find, find_len) == 0)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
