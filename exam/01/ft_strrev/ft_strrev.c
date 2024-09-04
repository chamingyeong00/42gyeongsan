/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:14:18 by micha             #+#    #+#             */
/*   Updated: 2024/08/18 20:36:05 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrev(char *str)
{
	int	i;
	int	len;
	char	temp;

	i = 0;
	len = 0;
	while (str[i] != '\0')
		len++;
	i = -1;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return (str);
}

int	main(void)
{
	char	a[] = "abcde";
	ft_strrev(a);
	write (1, a, 5);
}
