/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:20:02 by micha             #+#    #+#             */
/*   Updated: 2024/10/01 15:20:03 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (i < count)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dest);
}
