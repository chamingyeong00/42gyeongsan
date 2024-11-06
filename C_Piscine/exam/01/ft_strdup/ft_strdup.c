/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:37:23 by micha             #+#    #+#             */
/*   Updated: 2024/08/18 18:50:21 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(char *src)
{
	int	len;
	int	j;
	char	*dest;

	len = 0;
	while (src[len] != '\0')
		len++;
	dest = malloc(len + 1);
	j = 0;
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	main(void)
{
	char	a[] = "abc";
	write(1, ft_strdup(a), sizeof(a));
}
