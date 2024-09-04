/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:20:12 by micha             #+#    #+#             */
/*   Updated: 2024/08/12 11:16:02 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*int	ft_strlen(char *s1)
{
	int		i;

	i = 0;
	while(s1[i] != '\0')
	{
		i++;
	}
	return (i);
}


char	*ft_strcpy(char *s1, char *s2)
{
	int		i;
	int		strlen;

	strlen = ft_strlen(s1) + 1;
	i = 0;
	while(i <= strlen)
	{
		s2[i] = s1[i];
	}
	return (s2);
}*/

char	*ft_strcpy(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
/*int	main(void)
{
	char	a[4];
	char	b[4] = "abc";

	ft_strcpy(a, b);
	write(1, a, sizeof(b));
}*/
