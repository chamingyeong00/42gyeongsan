/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:18:50 by micha             #+#    #+#             */
/*   Updated: 2024/08/26 01:59:13 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	int	len;
	char	*res;
	int	i;

	len = ft_len(nbr);
	res = (char *)malloc(len * sizeof(char) + 1);
	if (res == 0)
		return (0);
	if (nbr == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	i = len - 1;
	while (nbr > 0)
	{
		res[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	return (res);
}

int	main(void)
{
	char *str = ft_itoa(2147483647);
    if (str != NULL)
    {
        printf("%s\n", str);
        free(str); // Free the allocated memory
    }
    return (0);
}
