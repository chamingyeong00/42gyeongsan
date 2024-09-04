/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:56:40 by micha             #+#    #+#             */
/*   Updated: 2024/08/21 15:05:08 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	unsigned int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		dest_len;
	unsigned int		src_len;
	unsigned int		i;
	unsigned int		j;

	dest_len = str_len(dest);
	src_len = str_len(src);
	i = dest_len;
	j = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[j] != '\0' && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest_len + src_len);
}
