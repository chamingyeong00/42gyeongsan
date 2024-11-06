/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:38:14 by micha             #+#    #+#             */
/*   Updated: 2024/08/12 09:52:58 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrev(char *str)
{
	int			i;
	int			strlen;
	char		temp;

	strlen = ft_strlen(str) - 1;
	i = 0;
	while (strlen > i)
	{
		temp = str[i];
		str[i] = str[strlen];
		str[strlen] = temp;
		i++;
		strlen--;
	}
	return (str);
}
