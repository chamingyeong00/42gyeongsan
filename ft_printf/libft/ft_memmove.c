/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:44:33 by micha             #+#    #+#             */
/*   Updated: 2024/10/01 15:44:34 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t count)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	i = -1;
	if (!dest && !src)
		return (0);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (src < dest)
	{
		while (++i < count)
			dest_ptr[(count - 1) - i] = src_ptr[(count - 1) - i];
	}
	else if (src >= dest)
	{
		while (++i < count)
			dest_ptr[i] = src_ptr[i];
	}
	return (dest);
}
