/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:14:15 by micha             #+#    #+#             */
/*   Updated: 2024/10/01 20:14:16 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int ch)
{
	int	i;
	int	temp;

	i = 0;
	temp = -1;
	while (str[i] != '\0')
	{
		if (str[i] == (char)ch)
			temp = i;
		i++;
	}
	if (str[i] == (char)ch)
		return ((char *)&(str[i]));
	if (temp != -1)
		return ((char *)&(str[temp]));
	return (0);
}
